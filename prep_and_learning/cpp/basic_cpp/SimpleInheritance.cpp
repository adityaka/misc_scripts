#include<iostream>
#include <Log.hh>
#include "SimpleInheritance.h"

ParentClass::ParentClass() {
    Logger::getLogger("ParentClass").info("Constructor Enter");
    Logger::getLogger("ParentClass").info("Constructor Exit");
}

void ParentClass::publicVirtualMethod() {
    Logger::getLogger("ParentClass").info("publicVirtualMethod Enter");
    Logger::getLogger("ParentClass").info("publicVirtualMethod Exit");
}

void ParentClass::publicMethod() {
    Logger::getLogger("ParentClass").info("publicMethod Enter");
    Logger::getLogger("ParentClass").info("publicMethod Exit");
}

void ChildClass::publicMethod() {
    Logger::getLogger("ChildClass").info("publicMethod Enter");
    Logger::getLogger("ChildClass").info("publicMethod Enter");
}

void ChildClass::publicVirtualMethod() {
    Logger::getLogger("ChildClass").info("publicVirtualMethod Enter");
    Logger::getLogger("ChildClass").info("pulicVirtualMethod Exit");
}

int main(int argc, char **argv) {
    ParentClass *p = new ChildClass();
    p->publicMethod();
    p->publicVirtualMethod();    
    return 0;
}
