#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<exception>
#include<ctime>
#include<chrono>

#ifndef PREP_AND_LEARN_UTILS_LOGGER
#define PREP_AND_LEARN_UTILS_LOGGER
namespace basic_cpp {
    namespace constrefs {
        enum class LogLevel {
            FATAL = 0x1,
            WARN  = 0x3,
            INFO  = 0x7,
            DEBUG = 0xf,
            TRACE = 0x1f
        };

        class Logger {
            public:
            static const std::string getLevelString(LogLevel level){
                switch(level) {
                    case LogLevel::FATAL : { return " FATAL "; }
                    case LogLevel::WARN : { return " WARN "; }
                    case LogLevel::INFO : { return " INFO "; }
                    case LogLevel::DEBUG : { return " DEBUG "; }
                    case LogLevel::TRACE : { return " TRACE "; }
                    default : { throw new std::invalid_argument("Bad Log Level Translation"); }
                }
            }

            static const std::string getCurrentTime() {
                std::time_t messageTime = std::chrono::system_clock::to_time_t(
                                          std::chrono::system_clock::now()
                                        );
                auto timestr =  std::string(std::ctime((const time_t*)&messageTime));
                return timestr;
            }

            static const Logger& getLogger(
                const std::string loggerName, 
                LogLevel level=LogLevel::INFO) {
                if (Logger::loggers.find(loggerName) == Logger::loggers.end() ) {
                    Logger::loggers[loggerName] =  new Logger(loggerName, level);
                }
                return *(loggers[loggerName]);
            }

            void log(std::string msg, LogLevel level) const {
                if (level > this->loggerLevel ) {
                    return;
                }
                const std::string& time = Logger::getCurrentTime();
                std::cerr << time << " "
                          << Logger::getLevelString(level)
                          << msg;
            } 

            void fatal(const std::string& msg) const {
                log(msg, LogLevel::FATAL);
            }

            void warn(const std::string& msg) const {
                log(msg, LogLevel::WARN);
            }

            void info(const std::string& msg) const {
                log(msg, LogLevel::INFO);
            }    

            void debug(const std::string& msg) const {
                log(msg, LogLevel::DEBUG);
            }

            void trace(const std::string& msg) const {
                log(msg, LogLevel::TRACE);
            }

            ~Logger() {
                this->info("Logger " + this->name + " Destroyed");
            }
            private:
            static std::map<std::string, Logger*> loggers;
            
            Logger(
                const std::string& loggerName,
                LogLevel level=LogLevel::INFO) {
                name = loggerName;
                loggerLevel = level;
            }

            std::string name;
            LogLevel loggerLevel;

        };
        std::map<std::string, Logger*> Logger::loggers;
    };
};

#endif