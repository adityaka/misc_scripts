import argparse 
import fnmatch
import os
import os.path 
import sys 

def main():
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("-r","--hadoop-root",help="Hadoop Dist root to scan for files",dest="hadoop_root")
    parser = arg_parser.parse_args() 

    if parser.hadoop_root is  None or \
    os.path.exists(parser.hadoop_root) is not True :
        arg_parser.print_help() 
        exit(-1) 
    if os.getuid() != 0:
        sys.stderr.writelines("You need to be root to delete the hadoop dist")
        arg_parser.print_help()
        exit(-1)

    walker = os.walk(parser.hadoop_root)
    for root,dirs,files in walker:
        for f in files:
            file_path = os.path.join(root,f).replace(parser.hadoop_root,"")
            if os.access(file_path,os.W_OK):
                os.remove(file_path)
                print "deleted " + file_path
                

if __name__ == "__main__":
    main()
