#include <ListNode.hh>

void singleListTest() {
    SingleListNode<int> *listHead = new SingleListNode<int>();
    SingleListNode<int> *listNextNode = new SingleListNode<int>();
    listHead->setNext(listNextNode);
    listHead->setData(2);
    listNextNode->setData(4);
    listNextNode->setNext(nullptr);
    
}

void doubleListTest() {
    DoubleListNode<int> *doubleListHead = new DoubleListNode<int>();
    DoubleListNode<int> *doubleListNode = new DoubleListNode<int>();
    doubleListHead->setNext(doubleListNode);
    doubleListHead->setPrev(nullptr);
    doubleListNode->setNext(nullptr);
    doubleListNode->setPrev(doubleListHead);
    doubleListHead->setData(2);
    doubleListNode->setData(4);
}



int main() {
    singleListTest();
    doubleListTest();
    return 0;
}