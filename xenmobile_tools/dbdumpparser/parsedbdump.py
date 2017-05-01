"""
This script module parses the ill-formed DbDump.json for xenmobile and splits the data into various tables 
it's easier to query and probably later we can use it in a UI as a tool 
"""

from __future__ import print_function,division,unicode_literals

import json
import os
import re
import argparse
import logging

logging.basicConfig(format="%(asctime),%(levelname)s,%(message)")
logger = logging.getLogger(__file__)

"""
This individual script can be used to dump different table jsons from the 
dbdump.json generated in the Xenmobile suppoer bundle. 
"""

#TODO : Logging configuration is a mess at the moment we need to work this one out 

OUTDIR_DEFAULT = "dbdump_out"

def getDbDumpIterator(dbDumpContent):
    """
    
    :param dbDumpContent: the json content from the DbDump.json file  
    :return: generator on the match objects to save some CPU on the loop
    """
    #in python 2 bytes and str are the same type
    if dbDumpContent is None or type(dbDumpContent) is not str:
        logger.fatal("DbDump Content should either be a string or byte string")
        raise

    matches =  re.finditer("\}\{",dbDumpContent)

    beginIndex=0
    endIndex = -1
    matchContent = None
    for match in matches:
        endIndex = match.span()[0]+1
        matchContent = dbDumpContent[beginIndex:endIndex]
        yield matchContent
        beginIndex = match.span()[1] -1


def main():
    """
    This the main shell and the file writer 
    :return: None  
    """
    parser = argparse.ArgumentParser()
    parser.add_argument("-i","--json-file",dest="jsonFile",help="path to DbDump.json file from the xenmobile file bundle")
    parser.add_argument("-o","--outdir",dest="outDir",help="output directory for the json files")

    arguments = parser.parse_args()
    inputFile = None
    outDir = None

    if hasattr(arguments,"jsonFile") is  False:
        logger.critical("cannot proceed without the json file")
        parser.print_help()
        raise

    if hasattr(arguments,"outDir") is  False:
        logger.warning("proceed without the out dir argument assuming output directory as current directory")
        outParent  = os.path.dirname(os.path.realpath(arguments.jsonFile))
        outDir = os.path.join(outParent,OUTDIR_DEFAULT)
    else:
        outDir = os.path.join(os.path.realpath(arguments.outDir),OUTDIR_DEFAULT)

    if os.access(outDir, os.W_OK) is False:
        os.makedirs(outDir)

    inputFile = arguments.jsonFile
    content = None
    with open(inputFile,"r") as infile:
        content = infile.read()

    iter = getDbDumpIterator(content)
    for m in iter:
        jsonContent = json.loads(m)
        logger.info(jsonContent.keys())
        outFileName = jsonContent.keys()[0] + ".json"
        outFilePath = os.path.join(outDir,outFileName)
        with open(outFilePath,"w+") as outFd:
            json.dump(jsonContent,outFd)
        print("Done processing Table {0}".format(outFileName))

    logger.info("Done!!!")




if __name__ == "__main__":
    main()


