// Created by Samina Faheem on 6/14/2022.

#ifndef SANDBOX_JUSTCODE_DSLINKEDLIST_H
#define SANDBOX_JUSTCODE_DSLINKEDLIST_H

#include "DSListNode.h"
#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class DSLinkedList {
private:
    DSListNode<T>* front;
    DSListNode<T>* back;
    DSListNode<T>* iterator;
    int size;

public:
    DSLinkedList();

    //Rule of 3
    DSLinkedList(const DSLinkedList<T>& arg);
    DSLinkedList<T>& operator=( const DSLinkedList<T>& );
    ~DSLinkedList();

    void push_front(const T arg);
    void push_back(const T arg);

    T& at(int location)const;
    void print();

    void back_iterator();
    void front_iterator();
    void increment_iterator();
    T& get_iterator();

    bool is_front();
    bool is_back();
    bool isnull ();

    void clear();
    int get_size();
    void insert(const T &arg, int location);
};

//constructor
template<typename T>
DSLinkedList<T>::DSLinkedList():front(nullptr), back(nullptr), iterator(nullptr), size(0) {}

//copy constructor
template<typename T>
DSLinkedList<T> ::DSLinkedList(const DSLinkedList<T>& arg){
    if(arg.front == nullptr){
        front= nullptr;
        back = nullptr;
        size = 0;
        iterator = nullptr;
    }
    else{
        front = new DSListNode<T>;
        front->data = arg.front->data;
        DSListNode<T> * arg_it;
        arg_it= arg.front-> next;

        DSListNode<T> * this_it;
        this_it= front;

        while(arg_it != nullptr){
            this_it-> next = new DSListNode<T>;
            this_it ->next->data = arg_it-> data;
            this_it -> next -> prev = this_it;
            this_it = this_it-> next;
            arg_it = arg_it-> next;
        }
        back = this_it;
        size = arg.size;
    }
}

//assignment operator
template<typename T>
DSLinkedList<T>& DSLinkedList<T> ::operator=(const DSLinkedList<T> &arg ) {
    clear();
    if(arg.front == nullptr){
        front= nullptr;
        back = nullptr;
        size = 0;
        iterator = nullptr;
    }
    else{
        front = new DSListNode<T>;
        front->data = arg.front->data;
        DSListNode<T> * arg_it;
        arg_it= arg.front-> next;

        DSListNode<T> * this_it;
        this_it= front;

        while(arg_it != nullptr){
            this_it-> next = new DSListNode<T>;
            this_it ->next->data = arg_it-> data;
            this_it -> next -> prev = this_it;
            this_it = this_it-> next;
            arg_it = arg_it-> next;
        }
        back = this_it;
        size = arg.size;
    }
    return *this;
}

//Destructor
template<typename T>
DSLinkedList<T>:: ~DSLinkedList(){
    clear();
}

// Pushing the contents in the front of a linked list
template<typename T>
void DSLinkedList<T> ::push_front(const T arg) {
    DSListNode<T> * temp = new DSListNode<T>(arg);
    temp-> next = front;
   if (front != nullptr ){
       front -> prev =temp;
   }
   else{
       back = temp;
   }
    front = temp;
   size++;
}

// Pushing the contents in the back of a linked list
template<typename T>
void DSLinkedList<T> ::push_back(const T arg) {
    DSListNode<T> * temp = new DSListNode<T>(arg);
    temp-> prev = back;
    if (back != nullptr ){
        back -> next =temp;
    }
    else{
        front = temp;
    }
    back= temp;
    size++;
}

//Location in the linked list
template<typename T>
T& DSLinkedList<T> ::at(int location)const {
  DSListNode<T> * curr = front;
  int count = 0;
  while(count < location && curr != nullptr)
  {
      count++;
      curr= curr ->next;
  }

  if(count == location  && curr != nullptr ){
      return curr -> data;
  }
    throw std::runtime_error("Linkedlist at function: out of bounds");

}

// Printing the linked list
template<typename T>
void DSLinkedList<T> :: print(){
    DSListNode<T> * curr = front;
    while(curr != nullptr)
    {
        cout<< curr ->data <<endl;
        curr = curr ->next;
    }
}

//Setting the iterator that would point to the back of the linked list
template<typename T>
void DSLinkedList<T> ::back_iterator(){
    iterator =back;
}

//Setting the iterator that would point to the front of the linked list
template<typename T>
void DSLinkedList<T> ::front_iterator(){
    iterator= front->next;

}

//incrementing the iterator
template<typename T>
void DSLinkedList<T> :: increment_iterator(){
    iterator = iterator ->next;
}

// returning the value associated with the node.
template<typename T>
T& DSLinkedList<T> :: get_iterator(){
 return iterator->data;
}

//returning the iterator that is pointing to front
template<typename T>
bool DSLinkedList<T>:: is_front(){
    return iterator == front->next;
}

//returning the iterator that is pointing to the back
template<typename T>
bool DSLinkedList<T>:: is_back(){
    return iterator == back;
}

// pointing to null
template<typename T>
bool DSLinkedList<T>:: isnull(){
    return iterator == nullptr;
}

// clearing or removing all the elements from the list
template<typename T>
void DSLinkedList<T>:: clear(){
    iterator = front;
    while(size>0){
        if(iterator->next!= nullptr){
            iterator -> next -> prev = iterator-> prev;
        }
        if(iterator->prev!= nullptr){
            iterator -> prev ->next = iterator-> next;
        }
        front= iterator->next;
        delete iterator;
        iterator = front;
        size--;
    }
    front = nullptr;
    back= nullptr;
    iterator = nullptr;
}

//getting the size of the linked lsit
template<typename T>
int DSLinkedList<T>:: get_size(){
    return size;
}

//inserting in linked list
template<typename T>
void DSLinkedList<T> ::insert(const T &arg, int location) {
    DSListNode<T> *temp = new DSListNode<T> (arg);
    if(location ==0){
        push_front(arg);
    }
    else {
        DSListNode<T> *curr = front;
        int counter = 0;
        while (curr != nullptr && counter < location) {
            curr = curr->next;
            counter++;
        }
        if(curr != nullptr && counter == location){
            temp -> next = curr;
            temp-> prev = curr -> prev;
            curr -> prev -> next = temp;
            curr -> prev =  temp;
        }
    }
    size++;
}
#endif //SANDBOX_JUSTCODE_DSLINKEDLIST_H