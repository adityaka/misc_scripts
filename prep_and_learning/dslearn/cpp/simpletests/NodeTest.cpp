#include<Node.hh>

int main() {
    Node<int> *shead = new Node<int>(1);
    shead->setData(2);
    shead->addLink(nullptr,0);
    Node<int> *nnode = new Node<int>(1);
    shead->addLink(nnode, 0);
    nnode->setData(4);

    Node<int> *dhead = new Node<int>(2);
    Node<int> *dnode = new Node<int>(2);
    dhead->addLink(dnode, 0);
    dhead->addLink(nullptr, 1);
    dnode->addLink(nullptr, 0);
    dnode->addLink(dhead, 1);
    dhead->setData(2);
    dnode->setData(4);
    
    delete shead;
    delete nnode;
    delete dhead;
    delete dnode;
    return 0;
}