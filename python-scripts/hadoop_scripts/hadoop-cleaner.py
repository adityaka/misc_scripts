import argparse 
import fnmatch
import os
import os.path 
import sys 
import logging 

"""
This one cleans the mess if you have installe hadoop installation forcefully 
to the root of the linux/unix system 
e.g. sudo cp -rvf ./hadoop-2.9.0-SNAPSHOT/* / 
"""
logging.basicConfig(format="%(asctime)s,%(levelname)s,%(message)s",level=logging.DEBUG)
logger = logging.getLogger(__file__) 

def main():
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("-r","--hadoop-root",help="Hadoop Dist root to scan for files",dest="hadoop_root")
    parser = arg_parser.parse_args() 

    if parser.hadoop_root is  None or \
    os.path.exists(parser.hadoop_root) is False:
        logging.error("Insufficient Arguments -hadoop-root is mandetory parameter")
        arg_parser.print_help() 
        exit(-1) 
    if os.getuid() != 0:
        logging.error("You need to be root to delete the hadoop dist")
        arg_parser.print_help()
        exit(-1)

    walker = os.walk(parser.hadoop_root)
    for root,dirs,files in walker:
        for f in files:
            file_path = os.path.join(root,f).replace(parser.hadoop_root,"")
            if os.access(file_path,os.W_OK):
                os.remove(file_path)
                logging.info("deleted " + file_path)
            elif os.path.exists(file_path) is False:
                logger.info(file_path + "doesn't exist")

if __name__ == "__main__":
    main()
