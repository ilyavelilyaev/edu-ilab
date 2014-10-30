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
#define STR_SIZE 1000

enum LIST_ERR_TYPE {
    NO_ERR,
    NULL_POINTER,
};

class Type {
public:
    long long number;
    char a[STR_SIZE];
};

class Node {
public:
    Type value;
    Node *next;
    Node *prev;
};

class List {
public:
    long long length;
    Node *head;
    List();
    LIST_ERR_TYPE push(Type *newItem);
    LIST_ERR_TYPE pop();
    LIST_ERR_TYPE insert();
    LIST_ERR_TYPE withdraw();
    ~List();
};


#endif
