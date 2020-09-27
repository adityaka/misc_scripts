package com.addy.learn.javads.basicjava;
import java.lang.IllegalArgumentException;

public class SimpleInheritance {
    public static interface List<ListType> {
        ListType get(int index);
        List<ListType> insert(ListType data, int index);
        List<ListType> append(ListType data);
        List<ListType> remove(int index);
        List<ListType> reverse();
    }

    public static class Node<NodeType> implements Serializable {
        
        public static final long serialVersionUID = 1;

        public void setData(NodeType data) {
            this.data = data;
        }

        public NodeType getData() {
            return data; 
        }

        public Node<NodeType> getNext() {
            return next;
        }

        public void setNext(Node<NodeType> node) {
            next = node;
        }

        private NodeType data;
        private Node<NodeType> next;
    };

    public static class SingleList<ListType> implements List<ListType> {
        
        public ListType get(int index) {
            int pos = 0;
            ListType res;
            for(Node<ListType> itr = head; itr != null; itr = itr.getNext()) {
                if (pos == index) {
                    res = itr.getData();
                    break;
                }
            }
            return res;
        }

        public boolean isEmpty() {
            return head == null ;
        }

        public List<ListType> insert(ListType data, int index) throws IllegalArgumentException{
            Node<ListType> node = new Node<>();
            node.setData(data);
            node.setNext(null);
            
            if( isEmpty() ) {
                head = node;
                tail = head;
            } else if (index < listLen ) {
                Node<ListType> prev = null;
                int pos =0;
                for(Node<ListType> itr = head; itr != null; itr=itr.getNext(), pos++ ) {
                    if(pos == index) {
                        if(prev != null) {
                            prev.setNext(node);
                            node.setNext(itr);
                        } else {
                            node.setNext(head);
                            head = node;
                        }
                    } else {
                        prev = itr;
                    }
                }
            } else if (index == listLen) {
                tail.setNext(node);
            } else {
                throw new IllegalArgumentException("List Index out of bounds");
            }
            return this;
        }

        public List<ListType> append(ListType data) {
            insert(data, listLen);
            return this;
        }

        public List<ListType> remove(int index) throws IllegalAccessError, IllegalArgumentException {
            if(isEmpty()) {
                throw new IllegalAccessError("remove called on empty list");
            }
            if(index > listLen) {
                throw new IllegalArgumentExcepton("Index out of bounds");
            }
            Node<ListType> prev  = null;
            int pos = 0;
            for (Node<ListType> itr = head; itr != null; itr = itr.getNext()) {
                if(pos == index) {
                    if (prev != null) {
                        prev.setNext(itr.getNext());
                        if(itr.getNext() == null){
                            tail = prev;
                        }
                    } else {
                        head = head.getNext();
                    }
                } else {
                    prev = itr;
                }
            }
        }

        public List<ListType> reverse() {

        }

        private Node<ListType> head = null;
        private Node<ListType> tail = null;
        private int listLen = 0;
    };

    public static void main(String[] args) {
        List<Integer> l = new SingleList<>();
        l.append(1).append(2).append(3).append(4);

    }
    
}