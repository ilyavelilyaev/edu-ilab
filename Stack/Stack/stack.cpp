//
//  stack.cpp
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "stack.h"


ERR_TYPE initializeStack (stack_type *stack) {
    
    stack_element_type *contents;
    
    contents = (stack_element_type *) calloc(sizeof(contents), 0);
    
    stack->data = contents;
    stack->size = 0;
    
    return NO_ERR;
}

ERR_TYPE pushData (stack_type *stack, const stack_element_type *content) {
    
    stack_element_type *newContents;
    newContents = (stack_element_type *) calloc(sizeof(newContents), stack->size + 1);
    
    for (int i = 0; i < stack->size; i++) {
        newContents[i] = stack->data[i];
    }
    
    newContents[stack->size] = *content;
    
    free(stack->data);
    
    stack->data = newContents;
    stack->size ++;

    
    return NO_ERR;
}


ERR_TYPE popData (stack_type *stack, stack_element_type *popped_content) {
    
    stack_element_type *newContents;
    newContents = (stack_element_type *) calloc(sizeof(newContents), stack->size - 1);

    *popped_content = stack->data[stack->size - 1];
    
    for (int i = 0; i < stack->size - 1; i++) {
        newContents[i] = stack->data[i];
    }
    
    free(stack->data);
    
    stack->data = newContents;
    stack->size --;
    
    return NO_ERR;
}