#include<iostream>

class RefTestClass {
    public:
        RefTestClass() {
            std::cout << "Entering RefTestClass Constructor " << "\n";
        }

        RefTestClass(RefTestClass& ref) {
            std::cout << "Entering RefTestClass Copy Constructor " << "\n";
            *this = ref;
        }

        ~RefTestClass() {
            std::cout << "Entering RefTestClass Destructor " << "\n";
        }
};

int& returnARef(){
    int *i = new int;
    *i = 2;
    std::cout << "Address pointed by  i = " << i << "\n"; 
    return *i;
}

int main(int argc, char **argv) {
    int *p = new int;
    std::cout << "Address pointed by  p = " << p << "\n";
    *p = 2;
    int &pref = *p;
    std::cout << "Address pointed by pref " << &pref << "\n";
    int& i = returnARef();
    std::cout << "got returned a reference = " << &i << "\n"; 
    RefTestClass o;
    auto r = o;
    auto &q = r;
    return 0;
}