//
//  stack.h
//  stack_cpp
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

typedef int element_t;

class Stack {
private:
    element_t *data;
    std::size_t size_of_stack;
public:
    Stack();
    bool empty();
    std::size_t size();
    element_t & top();
    void push(element_t content);
    void pop();
    ~Stack();
};

#endif /* defined(STACK_H) */
