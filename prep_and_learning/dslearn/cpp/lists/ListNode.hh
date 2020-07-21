#include<node.hh>

template<typename T>
class SingleListNode : public Node<T> {
    public:
    SingleListNode() : Node<T>(1) {

    }

    virtual SingleListNode<T>* next() {
        return static_cast<SingleListNode<T>*>(Node<T>::getLink(0));
    }
    
    virtual void setNext(SingleListNode<T>* node) {
        Node<T>::addLink(node, 0);
    }

    virtual ~SingleListNode() {

    }
    
};

template<typename T>
class DoubleListNode : public Node<T>  {
    public:
    DoubleListNode() : Node<T>(2)  {

    }

    virtual DoubleListNode<T>* next() {
        return static_cast<DoubleListNode<T>*>(Node<T>::getLink(0));
    }
    
    virtual void setNext(DoubleListNode<T>* node) {
        Node<T>::addLink(node, 0);
    }

    virtual DoubleListNode<T>* prev() {
        return static_cast<DoubleListNode<T>*>(Node<T>::getLink(1));
    }

    virtual void setPrev(DoubleListNode<T>* node) {
        Node<T>::addLink(node, 1);
    }

    virtual ~DoubleListNode() {

    }
};