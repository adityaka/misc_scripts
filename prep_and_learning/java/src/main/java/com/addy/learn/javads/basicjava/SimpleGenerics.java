package com.addy.learn.javads.basicjava;

import java.io.Serializable;

public class SimpleGenerics {

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

    public static void main(String[] args) {
        Node<Integer> head = new Node<Integer>();
        Node<Integer> node1 = new Node<Integer>();
        Node<Integer> node2 = new Node<Integer>();
        head.setData(2);
        node1.setData(4);
        head.setNext(node1);
        node1.setNext(node2);
        node2.setNext(null);
        node2.setData(6);

        for(Node<Integer> itr = head; itr != null; itr = itr.getNext() ) {
             System.out.println(itr.getData());
        }

    }
    
}