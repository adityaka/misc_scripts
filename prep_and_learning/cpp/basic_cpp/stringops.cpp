#include<string>
#include<iostream>

void passByReference(std::string& aref) {
    std::cout << "At Address " << &aref << aref << "\n"; 
}

void passByValue(std::string a) {
    std::cout << "At Address " << &a << a << "\n"; 
}



int main(int argc, char **argv) {
    std::string s = "Quick Brown Fox Jumped Over The Fence\n";
    std::cout << "address of s = " << &s  << "\n";
    //copy constructor should be called
    std::string t = s;
    std::cout << "address of t = " << &t  << "\n";
    // no copy constructor should be called 
    std::string& sref = s;
    std::cout << "address of sref = " << &sref  << "\n";
    std::cout << "pass by value address of = " << &t  << "\n";
    passByValue(t);
    std::cout << "pass by reference of s address = " << &s  << "\n";
    passByReference(s);
    return 0;
}
