# FileWatcher - a lay man code fixing excercise 

## SCENARIO 
This utility monitors a given directory and 
runs at the cli monitoring the directory using 
an infinite loop. It will scan all the files in 
the directory and then keep last line of each file 
in a static hashmap which has file path as key and 
last line of the file as reference point. 

Every iteration it read the file, compare the last 
line with the entry in the list. If the line is different
the utility will write the file name and timestamp to a 
log file. 

All files are assumed to be small text files and are constantly 
modified. 


## Excercise goals 
### Investigation Goals 

1. What is the impact on the machine's resources when we run this utility on as system?
2. What utilities and data can you collect to prove your observations? 
3. What would be the simplest code change to lower the impact on resources consumed? 
