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
#include <string>

#include "listExeptions.h"

class Node {
public:
    Node *next;
    Node *prev;
};


class List {
private:
    long long size_of_list;
   
public:
    Node *front_node;
    Node *back_node;
    List();
    List(List &obj);
    void push_front(Node *newNode);
    void push_back(Node *newNode);
    void pop_front();
    void pop_back();
    Node* front();
    Node* back();
    bool empty();
    long long& size();
    void insert(long long position, Node *newNode); //position is counting from front
    void erase(long long position);
    void clear();
    Node* operator[](long long position);
    List& operator=(List &x);
    ~List();
};


class FilesNode : public Node {
private:
    std::string name;
    std::string path; //with name
    std::string type; //"dir" or "file"
public:
    void setName(std::string new_name);
    void setPath(std::string new_path);
    void setType(unsigned char d_type);
    std::string getName();
    std::string getPath();
    std::string getType();
    FilesNode& operator=(FilesNode &x);
};


class ListNode : public Node {
public:
    List *list;
    char firstLetter;
};


#endif
