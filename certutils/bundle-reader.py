from OpenSSL import crypto
from argparse import ArgumentParser
import os
import re
import os.path

class CAFile(object):
    def __init__(self, filepath) -> None:
        if not os.access(filepath, os.R_OK):
            raise OSError("Can't find or read the bundle file %s" % filepath)
        self._file = open(filepath)
        self._cert_blobs = list()
        self._store = crypto.X509Store()
        self._store.load_locations(filepath)
        cert_buffer = list()
        cert_begin = False
        for line in self._file:
            if re.search("BEGIN.*CERTIFICATE", line) != None:
                line = "-----BEGIN CERTIFICATE-----\n"
                cert_begin = True
            if cert_begin:
                if re.search("END.*CERTIFICATE", line)  != None:
                    cert_begin = False
                    cert_buffer.append("-----END CERTIFICATE-----\n")
                    self._cert_blobs.append("".join(cert_buffer))
                    cert_buffer = list()
                else:
                    cert_buffer.append(line)

    def display_certs(self):
        for blob in self._cert_blobs:
            cert = crypto.load_certificate(type=crypto.FILETYPE_PEM, buffer=blob)
            print("Subject:%s, NotBefore: %s, NotAfter %s" % (cert.get_subject().commonName, str(cert.get_notBefore()), str(cert.get_notAfter())))

    def verify(self, cert_file_path):
        if not os.access(cert_file_path, os.R_OK):
            raise(ValueError("Cannot access %s" % cert_file_path))
        with open(cert_file_path) as cert:
            certblob = crypto.load_certificate(type=crypto.FILETYPE_PEM, buffer=cert.read())
            storeContext = crypto.X509StoreContext(store = self._store, certificate=certblob)
            try:
                verified_chain = storeContext.get_verified_chain()
                for chaincert in storeContext.get_verified_chain():
                    print(chaincert.get_subject())
            except crypto.X509StoreContextError as ce:
                print(str(ce))

    def extract(self, output_dir):
        if not os.access(output_dir, os.W_OK):
            try:
                os.makedirs(output_dir)
            except OSError as ose:
                print(ose)
        for blob in self._cert_blobs:
            cert = crypto.load_certificate(crypto.FILETYPE_PEM, blob)
            filename=str(cert.get_subject() + ".crt")
            with open(os.path.join(output_dir, filename), "w+") as f:
                f.write(blob)



def main():
    parser = ArgumentParser()
    parser.add_argument("-ca", "--cafile-path", dest="bundle_path", required=True, help="CA File which contains the store")
    subparsers = parser.add_subparsers()
    extract_parser = subparsers.add_parser("extract")
    extract_parser.add_argument("-o", "--output-dir", dest="output_dir", required=True, help="Output directory for extraction")
    verify_parser = subparsers.add_parser("verify")
    verify_parser.add_argument("-c", "--cert", dest="cert", required=True, help="cert file which needs to be verified")
    display_parser = subparsers.add_parser("display")
    display_parser.add_argument("-d","--display", dest="display", action="store_true", default=True, help="There is no need for this")
    args = parser.parse_args()

    cafile = CAFile(args.bundle_path)
    if hasattr(args, "cert"):
        cafile.verify(args.cert)
    elif hasattr(args, "output_dir"):
        cafile.extract(args.output_dir)
    elif hasattr(args, "display"):
        cafile.display_certs()

if "__main__" == __name__:
    main()(base)