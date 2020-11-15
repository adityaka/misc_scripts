#include<iostream>
#include<string>

// template resolution is two pass. 
// when inherited and not used with a base class name 
// we get a compilation error about arguments not dependant 
// on template parameters

template<typename T>
class Node {
    public:

    Node(int numberOfLinks) {
        this->numberOfLinks = numberOfLinks;
        links = new Node<T>*[numberOfLinks];
    }

    Node<T>* getLink(int pos) {
        if (pos > numberOfLinks) {
            throw "bad pos";
        }
        return links[pos];
    }

    void setLink(Node<T> *link, int pos) {
        if ( pos > numberOfLinks) {
            throw "bad pos";
        }
        links[pos] = link;
    }

    private:
    Node<T> **links;
    int numberOfLinks = 0;
};

template<typename T>
class SingleListNode : public Node<T> {
    public:

    SingleListNode() : Node<T>(1) {}

    SingleListNode<T>* next() {
        return Node<T>::getLink(0);
    }

    void setNext(SingleListNode<T> *node) {
        Node<T>::setLink(node, 0);
    }
};

int main() {
    SingleListNode<int> *head = new SingleListNode<int>();
    SingleListNode<int> *nextNode = new SingleListNode<int>();
    head->setNext(nextNode);
    nextNode->setNext(nullptr);
}