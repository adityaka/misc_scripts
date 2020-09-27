#include<iostream>
#include<SingleList.hh>

int main() {
    SingleList<int> s;
    s.append(2);
    s.append(3);
    s.append(4);
    s.append(1);
    s.append(6);

    s.remove(1);
    s.remove(0);
    s.remove(s.len() -1);

    s.insert(2,1);
    s.insert(3,2);
    s.insert(68, s.len());

    s.remove(0);
    
    for(int i = 0; i < s.len(); i++){
        std::cout << s.get(i) << " ";
    }
    std::cout << "\n";
}