#include "SimpleApp.hh"

class ParentClass {
    public:
    ParentClass() {

    }

    void publicMethod();
    virtual void publicVirtualMethod();

    protected:
    virtual void protectedVirtualMethod();

    int protectedInt = 10;

    private:
    int parentInt = 0;
};

class ChildClass : public ParentClass {
    public:
    ChildClass() {

    }

    public:
    void publicMethod();
    protected:
    virtual void protectedVirtualMethod();
    

};