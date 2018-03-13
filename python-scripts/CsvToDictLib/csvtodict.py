from csv import reader, Sniffer
from os import access, R_OK, W_OK, X_OK

class CSVImporter(object):
    """
    This class depnds on the python's csv module and
    returns the csv records along with header as a
    dictionary if first row has the header or as lists
    if there is no header.

    We can use the header properties to the set a new headers
    and use the object as an iterable or a generator

    """
    def __init__(self,csvfile,first_line_header=True):
        self.header = None
        self.csvfile = None
        self.csvfileobject = None
        self.first_line_header = first_line_header
        self.csv_file = csvfile


    @property
    def csv_file(self):
        try:
            file_path = getattr(self,"csvfile")
            return file_path
        except AttributeError:
            return None

    @csv_file.setter
    def csv_file(self,file_path):
        if access(file_path,R_OK):
            self.csvfile = file_path
            self.fileobject = open(self.csv_file,"r")
            self.dialect = Sniffer().sniff(self.fileobject.read(1024))
            self.fileobject.seek(0)
            self.csvfileobject = reader(self.fileobject,self.dialect)

            if self.first_line_header == True :
                self.csv_header = self.csvfileobject.next()

        else:
            raise IOError("Can't access csv file path for reading {0}".format(file_path))

    @property
    def csv_header(self):
        try:
            header = getattr(self,"header")
            return header
        except AttributeError:
            return None

    @csv_header.setter
    def csv_header(self,header):
        if len(header) > 0 and type(header) == list:
            self.header = header
        else:
            raise ValueError("can't have a empty header header has to be a list")

    def __iter__(self):
        return self

    def __next__(self):
        return self.next()

    def next(self):
        record = self.csvfileobject.next()
        result = None
        if self.csv_header != None :
            result = {}
            header_len = len(self.csv_header)
            for i in range(0,header_len):
                result[self.csv_header[i]] = record[i]
        else:
            result = record

        return result

    def __del__(self):
        self.fileobject.close()


## test code for csv with and without header
def test_csv_importer(csvfilename,header=True):
    csvimport = CSVImporter(csvfilename,header)
    for x in csvimport:
        print x
if __name__ == "__main__":
    csv_file = r"C:\Users\AdityaN\OneDrive\Projects\python\DevaReporter\RawReports\report2016.csv"
    test_csv_importer(csv_file,True)
    test_csv_importer(csv_file,False)

