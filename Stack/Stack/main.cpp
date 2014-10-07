//
//  main.cpp
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//


#include "stack.h"

int main(int argc, const char * argv[]) {
    
    stack_type myStack;
    int n, a;
    
    initializeStack(&myStack);
    
    scanf ("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        pushData(&myStack, &a);
    }
    
    
    for (int i = 0; i < n; i++) {
        popData(&myStack, &a);
        printf("%d\n", a);
    }
    
    return 0;
}
