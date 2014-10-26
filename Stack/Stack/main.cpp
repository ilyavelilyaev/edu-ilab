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
    //
    //uncomment if you want to check if stack normally behaves on pushing popping inserting and withdrawing
    //
    /*
    stack_element_type element;
    element.str[0] = 'a';
    element.str[1] = 0;
    element.anotherStr[0] = 'b';
    element.anotherStr[1] = 0;
    element.number = 1;
    pushData(&my_stack, &element);
    element.number = 2;
    pushData(&my_stack, &element);
    element.number = 3;
    pushData(&my_stack, &element);
    element.number = 4;
    insertData(&my_stack, &element, 1);
    withdrawData(&my_stack, &element, 2);
    popData(&my_stack, &element);
    */
    
    
    //
    //uncomment if you want to check if stack can use 2GB of memory
    //
    /*
    ERR_TYPE error;
    stack_element_type element;
    for (int i = 0; i<600000; i++) {
        element.number = i;
        element.str[0] = 'a' + i % 26;
        element.anotherStr[0] = 'a' + 25 - i % 26;
        element.str[1] = 0;
        element.anotherStr[1] = 0;
        error = pushData(&my_stack, &element);
        printf("i = %d --- error = %d my_stack.size = %lli\n", i, error, my_stack.size);
    
    }
    long long k = my_stack.size;
    for (int i = 0; i < k; i++) {
        popData(&my_stack, &element);
        printf("i = %d strings:%s %s\n",i, element.str, element.anotherStr);

    }
     */
    
    
    destroyStack(&my_stack);
    
    return 0;
}