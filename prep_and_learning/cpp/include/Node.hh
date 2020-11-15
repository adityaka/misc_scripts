#include<exception>

#ifndef PREP_AND_LEARN_DATASTRUCTURES_NODE_H
#define PREP_AND_LEARN_DATASTRUCTURES_NODE_H

class NoMoreLinksException :std::exception {
    virtual const char* what() {
        return "No more space to add links";
    }
};

class InvalidIndexException : std::exception {
    virtual const char* what() {
        return "Invalid index";
    }
};

template<typename T>
class Node {
    public:
    Node(int numberOfLinks) {
        this->links = new Node<T>*[numberOfLinks];
        this->numberOfLinks = numberOfLinks;
    }

    inline bool canAddMoreLinks() {
        return currentLinkPos+1 < numberOfLinks;
    }

    inline bool isValidIndex(int index) {
        return index >=0 && index < numberOfLinks;
    }

    void addLink(Node<T> *link, int pos) {
        if(!isValidIndex(pos)) {
            throw InvalidIndexException();
        }
        links[pos] = link;
    }

    inline T getData() {
        return data;
    }

    inline void setData(T data) {
        this->data = data;
    }

     Node<T>* getLink(int index) {
        if (!isValidIndex(index)) {
            return nullptr;
        } 
        return links[index];
    }

    virtual ~Node() {
        delete links;
    }
    private:
    T data;
    Node<T>** links;
    int numberOfLinks;
    int currentLinkPos;
};

#endif
