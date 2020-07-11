#include "App.hh"

class SimpleApp : protected App {

    public:

    SimpleApp() : App(0, nullptr) {
        
    }

    SimpleApp(int argc, char **argv) : App(argc, argv) {
        
    }

    virtual int main() = 0; 
};