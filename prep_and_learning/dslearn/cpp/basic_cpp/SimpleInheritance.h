#include <SimpleApp.hh>

class ParentClass {
    public:g++
    void publicMethod();
    virtual void publicVirtualMethod();

    /* protected:
    virtual void protectedVirtualMethod(); */

    int protectedInt = 10;

    private:
    int parentInt = 0;
};

class ChildClass : public ParentClass {
    
    public:
    virtual void publicMethod();
    virtual void pubicVirtualMethod();
    
   /*  protected:
    virtual void protectedVirtualMethod();
    */ 

};