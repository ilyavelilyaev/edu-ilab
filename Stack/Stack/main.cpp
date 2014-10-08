//
//  main.cpp
//  Stack
//
//  Created by Ilya Velilyaev on 24.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//
#include <string.h>
#include "stack.h"

void errorPrinter (ERR_TYPE error) {
    printf("ERROR! (%d):\n", error);
    switch (error) {
        case 1:
            printf("There is no memmory to allocate stack\n");
            break;
        case 2:
            printf("Stack is full\n");
            break;
        case 3:
            printf("Stack is empty\n");
            break;
        default:
            break;
    }
}

int analysString (const char *enteredString, stack_type *stack) {
    
    char command[10];
    stack_element_type value;
    ERR_TYPE error;
    
    sscanf(enteredString, "%s", command);
    
    
    if (strncmp(command, "help", 4) == 0 && strlen(enteredString) == 5) {
        printf("Available commands:\n\
               \"push 'value'\" - push to the stack 'value'\n\
               \"pop\" - pop the last element from the stack\n\
               \"destroy\" - destroy the stack\n\
               \"exit\" - exit application\n\
               more commands will be later\n");
        return 0;
    }
    
    if (strncmp(command, "push", 4) == 0) {
        char temp[30];
        int count = sscanf(enteredString, "%s %lld", temp, &value);
        
        if (count != 2) return -1; //error code
        
        error = pushData(stack, &value);
        if (error == NO_ERR) printf("pushed: %lld successfully\n", value);
        else errorPrinter(error);
        
        return 0;
    }
    
    if (strncmp(command, "pop", 3) == 0 && strlen(enteredString) == 4) {
        stack_element_type poppedElement;
        error = popData(stack, &poppedElement);
        if (error == NO_ERR) printf("popped: %lld\n",poppedElement);
        else errorPrinter(error);
        return 0;
    }
    
    if (strncmp(command, "destroy", 7) == 0 && strlen(enteredString) == 8) {
        initializeStack(stack);
        return 0;
    }
    
    if (strncmp(command, "exit", 4) == 0 && strlen(enteredString) == 5) {
        return 1; //exit code
    }
    
    
    return -1; //error code
}


int main (int argc, const char * argv[]) {
    
    stack_type myStack;
    ERR_TYPE error;
    
    error = initializeStack(&myStack);
    if (error != NO_ERR) {
        errorPrinter(error);
        return (int) error;
    }
    bool exit = false;
    while (!exit) {
    
        printf ("\nEnter commands (type \"help\" for help)\n");
    
        //entering string with spaces
        char enteredString[256];
        char temp[256], temp2[256];
        scanf("%s",temp);
        fgets (temp2, 256, stdin);
        strcpy(enteredString, temp);
        strcat(enteredString, temp2);
    
        int err = analysString(enteredString, &myStack);
        
        while (err == -1) {
            printf("\nUnknown command. Try again. If you need help, type \"help\"\n");
            //entering string with spaces
            char enteredString[256];
            char temp[256], temp2[256];
            scanf("%s",temp);
            fgets (temp2, 256, stdin);
            strcpy(enteredString, temp);
            strcat(enteredString, temp2);
            err = analysString(enteredString, &myStack);
        }
        if (err == 1) exit = true;
    }
    
    return 0;
}
