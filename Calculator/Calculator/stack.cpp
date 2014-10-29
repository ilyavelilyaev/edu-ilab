//
//  stack.cpp
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "stack.h"

ERR_TYPE initializeStack (stack_type *stack) {
    if (stack == NULL) return NULL_POINTER;
    stack->data = NULL;
    stack->size = 0;
    
    return NO_ERR;
}

ERR_TYPE pushData (stack_type *stack, const stack_element_type *content) {
    if (stack == NULL || content == NULL) return NULL_POINTER;
    
    //check if there is free memory for pushing one element
    if ((stack->size + 1) * sizeof(stack_element_type) > MAX_SIZE) return STACK_FULL;
    
    
    stack->data = (stack_element_type *) realloc(stack->data, sizeof(stack_element_type) * (stack->size + 1));
    stack->data[stack->size] = *content;
    
    stack->size ++;
    
    return NO_ERR;
}


ERR_TYPE popData (stack_type *stack, stack_element_type *popped_content) {
    if (stack == NULL || popped_content == NULL) return NULL_POINTER;

    //check if there are elements in stack;
    if (stack->size == 0) return STACK_EMPTY;
    
    *popped_content = stack->data[stack->size - 1];
    
    stack->data = (stack_element_type *) realloc(stack->data, sizeof(stack_element_type) * (stack->size - 1));

    stack->size --;
    
    return NO_ERR;
}

ERR_TYPE insertData (stack_type *stack, const stack_element_type *content, long long place) {
    if (stack == NULL || content == NULL) return NULL_POINTER;
    
    if (stack->size == 0) return STACK_EMPTY;
    
        
    stack->data = (stack_element_type *) realloc(stack->data, sizeof(stack_element_type) * (stack->size + 1));
    
    for (long long i = stack->size; i > place; i--) {
        stack->data[i] = stack->data[i - 1];
    }
    
    stack->data[place] = *content;
    
    stack->size++;
    
    
    return NO_ERR;
}

ERR_TYPE withdrawData (stack_type *stack, stack_element_type *withdrawen_content, long long place) {
    if (stack == NULL || withdrawen_content == NULL) return NULL_POINTER;
    
    //check if there are elements in stack;
    if (stack->size == 0) return STACK_EMPTY;
    
    *withdrawen_content = stack->data[place];
    
    for (long long i = place; i < stack->size - 1; i++) {
        stack->data[i] = stack->data[i + 1];
    }
    
    stack->data = (stack_element_type *) realloc(stack->data, sizeof(stack_element_type) * (stack->size - 1));
    
    stack->size --;
    
    return NO_ERR;
}



ERR_TYPE destroyStack (stack_type *stack) {
    if (stack == NULL) return NULL_POINTER;

    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    
    return NO_ERR;
}