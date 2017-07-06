package com.addy.learn.filewatcher;

import java.io.*;
import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Created by adityak on 7/5/17.
 */
public class FileWatcher extends  Thread {
    private String directoryPath;
    private HashMap<String,String> fileMap;
    public  static  long MONITOR_LENGTH = 10;
    public static Logger LOG = Logger.getLogger(FileWatcher.class.getName());

    public FileWatcher() {
        fileMap = new HashMap<String, String>();
    }

    public FileWatcher(String directoryPath) {
        this();
        this.directoryPath = directoryPath;
    }

    public String getDirectoryPath() {
        return directoryPath;
    }

    public void setDirectoryPath(String directoryPath) {
        this.directoryPath = directoryPath;
    }

    public HashMap<String, String> getFileMap() {
        return fileMap;
    }

    @Override
    public void run() {
        try {
            File f = new File(directoryPath);
            while(true) {
                if (f.exists()) {
                    if(f.isDirectory()){
                        File[] fileList = f.listFiles();
                        for(File file : fileList){
                            RandomAccessFile r = new RandomAccessFile(file,"r");
                            long fileSize = f.length();
                            if(fileSize <= 0){
                                continue;
                            }
                            long monitorLength = FileWatcher.MONITOR_LENGTH;
                            if(monitorLength > fileSize){
                                monitorLength = monitorLength - fileSize+1;
                            }

                            long beginReadingAt = fileSize - monitorLength;
                            byte[] fileContent = new byte[(int)monitorLength];
                            r.read(fileContent,(int)beginReadingAt,(int)(fileSize - beginReadingAt));
                            String content = new String(fileContent);
                            if(fileMap.containsKey(f.getName())){
                                String oldContent = fileMap.get(file.getName());
                                if(oldContent.equals(content)){

                                    continue;
                                }else{
                                    LOG.log(Level.INFO,String.format("%s has changed at %s", file.getName(), LocalDateTime.now().toString()));
                                    // to log file name
                                    fileMap.put(f.getName(),content);
                                }
                            }else{
                                LOG.log(Level.INFO,String.format("%s has changed at %s", file.getName(), LocalDateTime.now().toString()));
                                // to log file naame
                                fileMap.put(f.getName(),content);
                            }


                        }
                    }else{
                        LOG.log(Level.INFO,String.format("%s is not a directory exiting FileWatcher",f.getName()));
                        break;
                    }
                } else {
                    LOG.log(Level.INFO,String.format("%s is not found exiting FileWatcher"),f.getName());
                   break;

                }

            }
        } catch (FileNotFoundException e){
                LOG.log(Level.SEVERE,"FileNotFoundException this shouldn't happen");

        } catch (IOException e){
                LOG.log(Level.SEVERE,"IOException while reading the file");

        } catch (RuntimeException e) {
            LOG.log(Level.INFO,String.format("FileWatcher Thread Interrupted and exitting"));
        }
    }
}
