//
// Created by fahee on 6/14/2022.
//

#ifndef SANDBOX_JUSTCODE_DSADJACENCYLIST_H
#define SANDBOX_JUSTCODE_DSADJACENCYLIST_H

#include "DSLinkedList.h"

template<typename T>
class DSAdjacencyList {
public:
    void add_connections(const T& starting ,const  T& ending);
    DSLinkedList<T>& operator[] (const T& value);
    void reset_iterators();

private:
    DSLinkedList<DSLinkedList<T>> adj_list;//Entire
};

template<typename T>
void DSAdjacencyList<T> :: add_connections(const T& starting ,const  T& ending){
    for(int i =0; i< adj_list.get_size(); i++)
    {
        if(adj_list.at(i).at(0)== starting){
            adj_list.at(i).push_back(ending); //Adding the ending to the list of connectins to starting
            return;
        }
    }
    // if does not find then create new row for starting.
    DSLinkedList<T> new_row;
    new_row.push_back(starting);
    new_row.push_back(ending);
    adj_list.push_back(new_row);
}

template<typename T>
DSLinkedList<T>& DSAdjacencyList<T>:: operator[] (const T& value){
    for(int i =0; i< adj_list.get_size(); i++ ){
        if(adj_list.at(i).at(0)== value){
            return adj_list.at(i);
        }
    }
    DSLinkedList<T> temp;
    return temp;
}

template<typename T>
void DSAdjacencyList<T>:: reset_iterators(){
    for(int i =0; i< adj_list.get_size(); i++ ){
        adj_list.at(i).front_iterator();
    }
}

#endif //SANDBOX_JUSTCODE_DSADJACENCYLIST_H
