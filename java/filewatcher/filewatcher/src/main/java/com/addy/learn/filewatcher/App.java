package com.addy.learn.filewatcher;

import com.addy.learn.filegenerator.FileGenApp;

import java.util.logging.Filter;
import java.util.logging.Level;
import java.util.logging.LogRecord;
import java.util.logging.Logger;

/**
 * Hello world!
 *
 */


public class App 
{
    public static FileWatcher FILE_WATCHER_THREAD = null;
    public static FileGenApp FILE_GENERATOR_THREAD = null;
    public static Logger logger = Logger.getLogger(App.class.getCanonicalName());

    public static void main( String[] args )
    {
        logger.setLevel(Level.ALL);

        Runtime.getRuntime().addShutdownHook(new Thread(){
            @Override
            public void run() {
                if(!App.FILE_GENERATOR_THREAD.isInterrupted()){
                    System.out.println();
                    FILE_GENERATOR_THREAD.interrupt();
                }

                if(!App.FILE_WATCHER_THREAD.isInterrupted()){
                    FILE_WATCHER_THREAD.interrupt();
                }

                Runtime.getRuntime().exit(0);
            }
        });

    }
}
