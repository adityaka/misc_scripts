#include <List.hh>
#include <ListNode.hh>

#ifndef PREP_AND_LEARN_LISTS_DOUBLELIST_H
#define PREP_AND_LEARN_LISTS_DOUBLELIST_H
template<typename T>
class DoubleList : public List<T> {
    public:
    
    DoubleList() : List<T>() {
        listHead = nullptr;
        listLen = 0;
    }

    inline bool isEmpty() {
        return listHead == nullptr;
    }

    virtual int len() {
        return listLen;
    }

    virtual void append(T data) {
        insert(data, listLen);
    }

    virtual void insert(T data, int index) {
        DoubleListNode<T> *node = new DoubleListNode<T>();
        node->setData(data);
        node->setData(data);
        if(isEmpty()) {
            node->setNext(nullptr);
            node->setPrev(nullptr);
            listHead = node;
        } else if ( index >= listLen ) {
            for(DoubleListNode<T> *itr = listHead; itr != nullptr; itr=itr->next() ) {
                if (itr->next() == nullptr) {
                    itr->setNext(node);
                    node->setNext(nullptr);
                    break;
                }
            }
        } else {
            int pos = 0;
            DoubleListNode<T> *prev  = nullptr;
            for(DoubleListNode<T> *itr = listHead; itr != nullptr; itr = itr->next(), pos++) {
                if(pos == index) {
                    if(prev) {
                        node->setNext(prev->next());
                        node->setPrev(prev);
                        prev->setNext(node);
                        break;
                    } else {
                        node->setNext(listHead);
                        node->setPrev(nullptr);
                        listHead->setPrev(node);
                        listHead = node;
                        break;
                    }
                } else {
                    prev  = itr;
                }
            }
        }
        listLen++;
    }

    virtual void remove(int index) {
        if (index > listLen) {
            throw "index out of bounds";
        }

        if(isEmpty()) {
            throw "List is Empty";
        }

        int pos = 0;
        DoubleListNode<T> *prev = nullptr;
        for(auto itr = listHead; itr != nullptr; itr=itr->next(), pos++) {
            if(pos == index) {
                if(!prev) {
                    DoubleListNode<T> *tempHead = listHead;
                    DoubleListNode<T> *newHead = listHead->next();
                    newHead->setPrev(nullptr);
                    listHead = newHead;
                    delete tempHead;
                    break;
                } else {
                    DoubleListNode<T> *tempNode = itr;
                    DoubleListNode<T> *nextNode = itr->next();
                    prev->setNext(nextNode);
                    nextNode->setPrev(prev);
                    delete tempNode;
                    break;
                }
            } else {
                prev = itr;
            }
        }
        --listLen;
    }

    virtual T get(int index) {
        if(index >= listLen) {
            throw "Index out of bounds";
        }

        if(isEmpty()) {
            throw "List is Empty";
        }

        int pos = 0; 
        for(auto itr = listHead; itr != nullptr; itr = itr->next(), pos++) {
            if ( index == pos ) {
                return itr->getData();
            }
        }
    }

    virtual List<T>* reverse() {
        return nullptr;
    }

    private:
    DoubleListNode<T> *listHead;
    DoubleListNode<T> *listTail;
    int listLen;

};
#endif