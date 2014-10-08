//
//  stack.h
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define MAX_SIZE 2147483648


#include <stdio.h>
#include <stdlib.h>


typedef long long stack_element_type;

typedef struct {
    stack_element_type *data;
    long long size;
} stack_type;

enum ERR_TYPE {
    NO_ERR,
    NO_MEMORY,
    STACK_FULL,
    STACK_EMPTY,
    
};

//Initialize or Destroy stack
ERR_TYPE initializeStack (stack_type *stack);

//push data to the top
ERR_TYPE pushData (stack_type *stack, const stack_element_type *content);

//pop data from the top
ERR_TYPE popData (stack_type *stack, stack_element_type *popped_content);

//insert data in place (place is counting from bottom)
ERR_TYPE insertData (stack_type *stack, const stack_element_type *content, long long place);


#endif