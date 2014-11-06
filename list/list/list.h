//
//  list.h
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef LIST_H
#define LIST_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

class Node {
public:
    int value;
    Node *next;
    Node *prev;
};

class List {
private:
    long long size_of_list;
    Node *front_node;
    Node *back_node;
public:
    List();
    void push_front(const int &newItem);
    void push_back(const int &newItem);
    void pop_front();
    void pop_back();
    int& front();
    int& back();
    bool empty();
    long long size();
    void insert(long long position, const int &val); //position is counting from front
    void erase(long long position);
    void clear();
    int& operator[](long long position);
    List& operator=(List &x);
    ~List();
};

#endif
