#include<iostream>
#include<string>
#include<map>
#include <Logger.hh>


int main(void) {
    auto logger = basic_cpp::constrefs::Logger::getLogger("default", 
                                                         basic_cpp::constrefs::LogLevel::DEBUG);
    logger->warn("This is a warning message\n");                                                  
    logger->info("This is a info Message\n");
    logger->debug("this is a debug message\n");
    logger->trace("this is a trace message\n");
}