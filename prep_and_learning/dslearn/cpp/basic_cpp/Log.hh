#ifndef BASICS_LOG_H
#define BASICS_LOG_H
#include<string>
#include<iostream>
#include<sstream>
#include<cstdio>
#include<chrono>
#include<map>

enum class LoggingLevel {
    FATAL = 0x1,
    WARN  = 0x3,  
    INFO  = 0x7,
    DEBUG = 0xF
};

class LogMessage {

    public:
    static std::string getMessage(std::string topic, std::string message){
        std::stringstream ss;  
        ss <<  LogMessage::getCurrentTime() << " - " << message;
        return ss.str();
    }

    private:
    static const std::string& getCurrentTime() {
        std::time_t messageTime = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()
            );

        return std::string(std::ctime((const time_t*)&messageTime));
    }


};

class Logger {
    public:
    static const Logger& getLogger(
        std::string& loggerName,
        std::ostream *logStream =  &std::cerr,
        LoggingLevel level = LoggingLevel::INFO ) {

        if (loggers.find(loggerName) == loggers.end()) {
            loggers[loggerName] = *(new Logger(loggerName,logStream, level));
        }
        return loggers[loggerName];

    }

    void fatal(const std::string& message){
        switch(this->loggingLevel){
            case LoggingLevel::FATAL: {
                *logSink << LogMessage::getMessage(this->loggerName, message).c_str() << "\n";
                break;
            }
            
        }
    }
    void warn(const std::string& message){
        switch(this->loggingLevel){
            case LoggingLevel::FATAL:
            case LoggingLevel::WARN:{
                *logSink << LogMessage::getMessage(this->loggerName, message).c_str() << "\n";
                break;
            }
        } 
    }

    void info(const std::string& message){
        switch(this->loggingLevel){
            case LoggingLevel::INFO:
            case LoggingLevel::FATAL:
            case LoggingLevel::WARN:{
                *logSink << LogMessage::getMessage(this->loggerName, message).c_str() << "\n";
                break;
            }   
        }    
    }

    void info(const std::string& message){
        switch(this->loggingLevel){
            case LoggingLevel::DEBUG:
            case LoggingLevel::INFO:
            case LoggingLevel::FATAL:
            case LoggingLevel::WARN:{
                *logSink << LogMessage::getMessage(this->loggerName, message).c_str() << "\n";
                break;
            }   
        }    
    }


    private:
    Logger(std::string& loggerName,
           std::ostream* logStream,
           LoggingLevel level = LoggingLevel::INFO) {

            this->loggerName = loggerName;
            this->logSink = logStream;
            this->loggingLevel = level;

    }

    std::string loggerName;
    std::ostream *logSink;
    LoggingLevel loggingLevel;

    static std::map<std::string, Logger&> loggers;
};
#endif