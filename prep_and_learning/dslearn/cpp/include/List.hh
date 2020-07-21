
#ifndef PREP_AND_LEARN_DATASTRUCTURES_LIST_H
#define PREP_AND_LEARN_DATASTRUCTURES_LIST_H
template<typename T>
class List {
    public:
    virtual int len() = 0;
    virtual void append(T data) = 0;
    virtual void insert(T data, int index) = 0;
    virtual void remove(int index)=0;
    virtual List* reverse()=0; 
};
#endif