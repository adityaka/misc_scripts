#!/usr/bin/env python

import os 
import re
import fnmatch 
import argparse 
import sys 

def replace_pattern_in_file(file_path,regex_pattern,replacement_string):
    
    file_object = open(file_path,"rwt+")
    lines_buffer = file_object.readlines() 
    number_of_lines = len(lines_buffer)
    i = 0
    
    while i < number_of_lines:
        if re.search(regex_pattern,lines_buffer[i]) >= 0:
            lines_buffer[i] = re.sub(regex_pattern,replacement_string,lines_buffer[i])
        i+=1

    file_object.seek(os.SEEK_SET)
    file_object.truncate() 
    file_object.writelines(lines_buffer)
    file_object.close()  
            

def find_file_with_pattern_in_directory(root_directory,file_pattern):
    result = []
    walker = os.walk(root_directory)
    for root,dirs,files in walker:
        for f in files:
            if fnmatch.fnmatch(f,file_pattern):
                #yield os.path.join(root,f) 
                # need more understanding around why the heck 
                # generator code didn't workout
                path = os.path.join(root,f)
                result.append(path)
    return result

def replace_pattern_in_files(root_directory,file_pattern,regex_pattern,replacement_string):
    file_gen = find_file_with_pattern_in_directory(root_directory,file_pattern)
    for file in file_gen:
        replace_pattern_in_file(file,regex_pattern,replacement_string)

def main():
    argument_parse = argparse.ArgumentParser()
    argument_parse.add_argument('--directory'    ,'-d',dest='directory'    ,help="directory to scan for files, default is cwd",default=os.getcwd())
    argument_parse.add_argument('--file-pattern' ,'-f',dest='file_pattern' ,help="shell regex for type of files to be scanned ",default="*.*")
    argument_parse.add_argument('--regex-pattern','-p',dest='regex_pattern',help="regular expression or string which needs to be replaced")
    argument_parse.add_argument('--replacement'  ,'-r',dest='replacement'  ,help="replacement string") 

    parser = argument_parse.parse_args()
    if not os.path.isabs(parser.directory):
        parser.directory = os.path.abspath(parser.directory)
    
    if not os.path.isdir(parser.directory):
        raise ValueError("Not a directory")
    
    if not os.access(parser.directory,os.R_OK):
        raise IOError("Cannot access the root directory for reading")
    
    replace_pattern_in_files(parser.directory,parser.file_pattern,parser.regex_pattern,parser.replacement) 


    

if __name__ == "__main__":
    main() 