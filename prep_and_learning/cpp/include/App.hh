
#ifndef BASICS_APP_H
#define BASICS_APP_H

#include <errno.h>


class App {
    public:

    App(int argc, char **argv){
        this->argc = argc;
        this->argv = argv;
    }

    virtual int operator ()(int argc, char **argv) {
        defineAppArgs();
        if (!parseCommandLineArgs()) {
            return EINVAL;
        }
        main();
    }

    protected:
    virtual bool parseCommandLineArgs() {
        if (argc > 0) {
            appname = argv[0];
            if (argc < 1 && appParserDefined) {
                
            }
        } 
        return true;
    }

    virtual bool validateCommandLineArgs() {
        return true;
    }

    virtual void defineAppArgs() {
      
    }

    virtual int main() = 0; 

    private:
    int argc;
    char **argv;
    char *appname;
    bool appParserDefined = false;
};

#endif