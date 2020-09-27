#include <List.hh>
#include <ListNode.hh>

#ifndef PREP_AND_LEARN_LISTS_SINGLELIST_H
#define PREP_AND_LEARN_LISTS_SINGLELIST_H
template<typename T>
class SingleList : public List<T> {
    public:
    SingleList() : List<T>() {
        listHead = nullptr;
        listLen = 0;
        listTail = nullptr;
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

    virtual T get(int index) {
        if (isEmpty()) {
            throw "Empty List";
        }
        int pos = 0;
        for(SingleListNode<int> *itr = listHead; itr != nullptr; itr = itr->next(), pos++) {
            if (pos == index) {
                return itr->getData();
            }
        }
    }

    virtual void insertWithTail(T data, int index) {
        SingleListNode<T> *node = new SingleListNode<T>();
        node->setData(data);
        if(isEmpty()) {
            listHead = node;
            listTail = listHead;
            listHead->setNext(nullptr);
        } else if (index == listLen) {
            listTail->setNext(node);
            listTail = node;
            listTail->setNext(nullptr);
        } else if (index < listLen) {
            SingleListNode<T> *prev = nullptr;
            int pos = 0;
            for(auto itr = listHead; itr != nullptr; itr = itr->next(), pos++) {
                if (pos == index){
                    if(prev) {
                        node->setNext(itr);
                        prev->setNext(node);
                    } else {
                        node->setNext(listHead);
                        listHead = node;
                    }
                } else {
                    prev = itr;
                }
            }
        } else {
            throw "Invalid Index";
        }
        listLen++;
    }

    virtual void insert(T data, int index) {
        SingleListNode<T> *node = new SingleListNode<T>();
        node->setData(data);
        if (isEmpty()) {
                listHead = node;
                listHead->setNext(nullptr);
        } else if (index == listLen ) {
            node->setNext(nullptr);
            for(SingleListNode<T> *itr = listHead; itr != nullptr; itr=itr->next()) {
                if( itr->next() == nullptr) {
                    itr->setNext(node);
                    break;
                }
            }
        } else {
            int pos = 0;
            SingleListNode<T>* prev; 
            for(SingleListNode<T> *itr = listHead; itr != nullptr; itr=itr->next(), pos++) {
                if (pos == index) {
                    SingleListNode<T> *temp = prev->next();
                    prev->setNext(node);
                    node->setNext(temp);
                    break;
                } else {
                    prev = itr;
                }
            }
        }
        ++listLen;
    }

    virtual void remove(int index) {
        if(isEmpty()){
            throw "Empty list";
        }
        
        if(index >= listLen) {
            throw "invalid index";
        }

        SingleListNode<T> *node=nullptr;
        SingleListNode<T> *prev=nullptr;
        int pos = 0;
        for(SingleListNode<T> *itr = listHead; itr != nullptr; itr=itr->next(), pos++) {
            if (pos == index) {
                node = itr;
                SingleListNode<T> *temp = itr->next();
                if(prev) {
                    prev->setNext(temp);
                } else {
                    // if prev is null then it's a head removal
                    listHead = temp;
                }
                break;
            } else {
                prev = itr;
            }
        }
        delete node;
        --listLen;
    }

    virtual List<T>* reverse() {
        return nullptr;
    }

    virtual ~SingleList() {

    }

    private:
    SingleListNode<T>* listHead;
    SingleListNode<T>* listTail;
    int listLen;
    
};
#endif