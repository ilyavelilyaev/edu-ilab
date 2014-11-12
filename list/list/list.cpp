//
//  list.cpp
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "list.h"

void FilesNode::setName(std::string new_name) {
    name = new_name;
}

void FilesNode::setPath(std::string new_path) {
    path = new_path;
}

void FilesNode::setType(unsigned char d_type) {
    if (d_type == '\x04') type = "dir";
    else if (d_type == '\b') type = "file";
    else throw no_such_filetype();
}

std::string FilesNode::getName() {
    return name;
}

std::string FilesNode::getPath() {
    return path;
}

std::string FilesNode::getType() {
    return type;
}

FilesNode& FilesNode::operator=(FilesNode &x) {
    if (this == &x) return *this;
    name = x.getName();
    path = x.getPath();
    type = x.getType();
    return *this;
}


List::List() {
    size_of_list = 0;
    front_node = NULL;
    back_node = NULL;
}

List::~List() {
    clear();
}

void List::push_front(Node *newNode) {
    if (empty()) {
        front_node = newNode;
        front_node->prev = NULL;
        front_node->next = NULL;
        back_node = newNode;
        back_node->prev = NULL;
        back_node->next = NULL;
    } else {
        front_node->prev = newNode;
        newNode->next = front_node;
        newNode->prev = NULL;
        front_node = newNode;
    }
    size_of_list++;
    
}

void List::push_back(Node *newNode) {
    if (empty()) {
        front_node = newNode;
        front_node->prev = NULL;
        front_node->next = NULL;
        back_node = newNode;
        back_node->prev = NULL;
        back_node->next = NULL;
    } else {
        back_node->next = newNode;
        newNode->prev = back_node;
        newNode->next = NULL;
        back_node = newNode;
    }
    size_of_list++;
}

void List::pop_front() {
    if (empty()) throw list_empty();
    if (front_node->next != NULL) {
        front_node = front_node->next;
        delete front_node->prev;
        front_node->prev = NULL;
        size_of_list--;
    } else {
        delete front_node;
        size_of_list = 0;
    }
}

void List::pop_back() {
    if (empty()) throw list_empty();
    if (back_node->prev != NULL) {
        back_node = back_node->prev;
        delete back_node->next;
        back_node->next = NULL;
        size_of_list--;
    } else {
        delete back_node;
        size_of_list = 0;
    }
}

Node* List::front() {
    if (empty()) throw list_empty();
    return front_node;
}

Node* List::back() {
    if (empty()) throw list_empty();
    return back_node;
}

bool List::empty() {
    if (size() == 0) return true;
    return false;
}

long long List::size() {
    return size_of_list;
}

void List::insert(long long position, Node *newNode) {
    if (position > size()) throw out_of_size();
    if (position == 0) {
        push_front(newNode);
        return;
    }
    if (position == size_of_list) {
        push_back(newNode);
        return;
    }
    Node *temp = front_node;
    for (long long i = 0; i < position; i++) {
        temp = temp->next;
    }
    Node *temp2 = temp->prev;
    temp->prev = newNode;
    newNode->prev = temp2;
    temp2->next = newNode;
    newNode->next = temp;
    size_of_list++;
}

void List::erase(long long position) {
    if (position >= size()) throw out_of_size();
    if (position == 0) {
        pop_front();
        return;
    }
    if (position == size_of_list - 1) {
        pop_back();
        return;
    }
    Node *temp = front_node;
    for (long long i = 0; i < position; i++) {
        temp = temp->next;
    }
    Node *temp1 = temp->prev;
    Node *temp2 = temp->next;
    temp1->next = temp->next;
    temp2->prev = temp->prev;
    delete temp;
    size_of_list--;
}

void List::clear() {
    if (!empty()) {
        Node *node = NULL;
        if (front_node != NULL) node = front_node->next;
        Node *node1 = front_node;
        while (node1 != NULL) {
            delete node1;
            node1 = node;
            if (node != NULL) node = node->next;
        }
        front_node = NULL;
        back_node = NULL;
        size_of_list = 0;
    }
}

Node* List::operator[](long long position) {
    if (position >= size()) throw out_of_size();
    if (position == 0) return(front());
    if (position == size_of_list - 1) return(back());
    Node *temp = front_node;
    for (long long i = 0; i < position; i++) {
        temp = temp->next;
    }
    return temp;
}

List& List::operator=(List &x) {
    if (this == &x) return *this;
    clear();
    for (long long i = 0; i < x.size(); i++) {
        push_back(x[i]);
    }
    return *this;
}

List::List (List &x) {
    size_of_list = 0;
    front_node = NULL;
    back_node = NULL;
    for (long long i = 0; i < x.size(); i++) {
        push_back(x[i]);
    }
}
