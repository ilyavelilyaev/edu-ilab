//
//  stack.cpp
//  stack_cpp
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "stack.h"

Stack::Stack() {
    data = NULL;
    size_of_stack = 0;
}

bool Stack::empty() {
    if (size_of_stack == 0)
        return true;
    return false;
}

std::size_t Stack::size() {
    return size_of_stack;
}

element_t & Stack::top() {
    if (empty()) {
        throw "stack is empty";
    }
    return data[size_of_stack - 1];
}

void Stack::push(element_t content) {
    data = (element_t *)realloc(data, sizeof(element_t) * (size() + 1));
    data[size()] = content;
    size_of_stack ++;
}

void Stack::pop() {
    if (empty()) {
        throw "stack is empty";
    }
    data = (element_t *)realloc(data, sizeof(element_t) * (size() - 1));
    size_of_stack --;
}

element_t & Stack::operator[](std::size_t pos) {
    return data[pos];
}


Stack::~Stack() {
    free(data);
}