// Created by Samina Faheem on 6/14/2022.

#ifndef SANDBOX_JUSTCODE_DSLISTNODE_H
#define SANDBOX_JUSTCODE_DSLISTNODE_H

template<typename T>
class DSListNode {
public:
    T data;
    DSListNode<T>* next;
    DSListNode<T>* prev;

    DSListNode();
    DSListNode(const T& arg, DSListNode* n= nullptr,DSListNode *p= nullptr);
    DSListNode(const DSListNode& arg);
    DSListNode<T>  operator=(const DSListNode& arg);

};

template<typename T>
DSListNode<T>::DSListNode(){
    next= prev= nullptr;
}

template <typename T>
DSListNode<T>::DSListNode(const DSListNode& arg){
    next= arg.next;
    prev = arg.prev;
    data = arg.data;
}

template<typename T>
DSListNode<T>::DSListNode(const T& arg, DSListNode* n,DSListNode *p) {
    next= n;
    prev = p;
    data = arg;
}

template<typename T>
DSListNode<T> DSListNode<T> ::operator=(const DSListNode& arg ){
    next= arg.next;
    prev = arg.prev;
    data = arg.data;
    return *this;
}
#endif //SANDBOX_JUSTCODE_DSLISTNODE_H
