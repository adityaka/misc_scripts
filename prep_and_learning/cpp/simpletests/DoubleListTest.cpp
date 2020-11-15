#include<DoubleList.hh>
#include<iostream>

template<typename T> 
inline void displayList(const std::string& message, DoubleList<T>& list) {
    std::cout << message << "\n";
    for(int i =0; i < list.len(); i++){
        std::cout << list.get(i) << "\n";
    }
}

int main() {
    DoubleList<int> list;
    list.append(2);
    list.append(4);
    list.append(6);
    list.append(8);
    list.append(10);
    displayList("After append", list);
    list.remove(2);
    list.remove(0);
    //list.remove(list.len()-1);
    displayList("After Removal", list);
    list.insert(2,0);
    list.insert(12,list.len());
    displayList("After insertion ", list);
    
}