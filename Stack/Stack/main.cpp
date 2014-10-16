//
//  main.cpp
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "stack.h"


int main() {
    
    stack_type my_stack;
    
    initializeStack(&my_stack);
    
    ERR_TYPE error;
    stack_element_type element;

    for (int i = 0; i<6000000; i++) {
        element.number = i;
        element.str[0] = (char) i % 256;
        element.anotherStr[0] = (char) 256 - (i % 256);
        element.str[1] = 0;
        element.anotherStr[1] = 0;
        error = pushData(&my_stack, &element);
        printf("i = %d --- error = %d my_stack.size = %lli\n", i, error, my_stack.size);
    
    }
    
    printf("%s %s\n",my_stack.data[500000].str, my_stack.data[40000].anotherStr);
    
    for (int i = 1; i< 1000000000; i++) {
        i = 1;
    }
    destroyStack(&my_stack);
    
    return 0;
}