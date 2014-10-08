//
//  stack.cpp
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "stack.h"

ERR_TYPE initializeStack (stack_type *stack) {
    
    //create array and allocate memory for it
    stack_element_type *contents;
    contents = (stack_element_type *) malloc(0);
    
    //check if new array has allocated
    if (contents == NULL) return NO_MEMORY;
    
    //change the address of stack data and size of stack
    stack->data = contents;
    stack->size = 0;
    
    return NO_ERR;
}

ERR_TYPE pushData (stack_type *stack, const stack_element_type *content) {
    
    //check if there is free memory for pushing one element
    if ((stack->size + 1) * sizeof(stack->data) > MAX_SIZE) return STACK_FULL;
    
    //create new array and allocate memory for it
    stack_element_type *newContents;
    newContents = (stack_element_type *) malloc(sizeof(newContents) * stack->size + 1);
    
    //check if new array has allocated
    if (newContents == NULL) return NO_MEMORY;
    
    //copy all old data to new array
    for (int i = 0; i < stack->size; i++) {
        newContents[i] = stack->data[i];
    }
    
    //add pushing element to new array
    newContents[stack->size] = *content;
    
    //free old data memory
    free(stack->data);
    
    //change the address of stack data to new array and increase the size of stack
    stack->data = newContents;
    stack->size ++;

    
    return NO_ERR;
}


ERR_TYPE popData (stack_type *stack, stack_element_type *popped_content) {
    
    //check if there are elements in stack;
    if (stack->size == 0) return STACK_EMPTY;
    
    //create new array and allocate memory for it
    stack_element_type *newContents;
    newContents = (stack_element_type *) malloc(sizeof(newContents) * stack->size - 1);
    
    //check if new array has allocated
    if (newContents == NULL) return NO_MEMORY;
    
    *popped_content = stack->data[stack->size - 1];
    
    //copy old data without top element to new array
    for (int i = 0; i < stack->size - 1; i++) {
        newContents[i] = stack->data[i];
    }
    
    //free old data memory
    free(stack->data);
    
    //change the address of stack data to new array and decrease the size of stack
    stack->data = newContents;
    stack->size --;
    
    return NO_ERR;
}


ERR_TYPE insertData (stack_type *stack, const stack_element_type *content, long long place) {
    
    
    
    
    
    return NO_ERR;
}