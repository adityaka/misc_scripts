#include<bits/stdc++.h>
#include<syslog.h>

class SyslogMultiThreadedTest {

    public:
    static std::stringstream ERR_STREAM;
    static std::mutex STOP_MUTEX;
    static std::mutex STREAM_MUTEX;

    SyslogMultiThreadedTest() {
        openlog("SyslogTest", LOG_CONS,LOG_SYSLOG);
    }

    static void threadSyslogger() {
        int iteration = 1;
        do {
            // comment this lock to get the crash simulation
            std::lock_guard<std::mutex> streamLock(STREAM_MUTEX);
            ERR_STREAM << "\r\nThis is thread iteration" << iteration << "logging to syslog\n";
            syslog(LOG_CRIT, ERR_STREAM.str().c_str());
            ERR_STREAM.clear();
            iteration++;
        } while(!checkStop());
    }

    void start() {
        t1 = new std::thread(SyslogMultiThreadedTest::threadSyslogger);
        t2 = new std::thread(SyslogMultiThreadedTest::threadSyslogger);
        t1->detach();
        t2->detach();
    }

    void stop() {
        std::lock_guard<std::mutex> lock(STOP_MUTEX);
        stopTest=true;
    }

    ~SyslogMultiThreadedTest() {
        closelog();
    }

    private:
    std::thread *t1;
    std::thread *t2;
    static bool stopTest;
    
    static bool checkStop(){
        std::lock_guard<std::mutex> lock(STOP_MUTEX);
        return stopTest;
    }
};

std::stringstream SyslogMultiThreadedTest::ERR_STREAM;
std::mutex SyslogMultiThreadedTest::STOP_MUTEX;
bool SyslogMultiThreadedTest::stopTest = false;
std::mutex SyslogMultiThreadedTest::STREAM_MUTEX;

int main(int argc, char **argv) {
    SyslogMultiThreadedTest test;
    test.start();
    std::cout << "PRESS ENTER TO STOP";
    char *s = new char[1];
    std::cin.getline(s,1);
    delete s;
    test.stop();
}