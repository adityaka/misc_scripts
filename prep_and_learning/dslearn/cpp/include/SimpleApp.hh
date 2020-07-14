#include "App.hh"

class SimpleApp : protected App {

    public:
    SimpleApp(char **argv) : App(1, argv) {
    }

    virtual int main() = 0; 
};