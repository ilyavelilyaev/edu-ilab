//
//  calc.cpp
//  Calculator
//
//  Created by Ilya Velilyaev on 27.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "calc.h"

CALC_ERR_TYPE makeOperation (int operand, stack_type *stack) {
    CALC_ERR_TYPE error = CALC_NO_ERR;
    if (stack == NULL) return CALC_NULL_POINTER;
    stack_element_type temp1 = 0, temp2 = 0;
    error = (CALC_ERR_TYPE) popData(stack, &temp1);
    error = (CALC_ERR_TYPE) popData(stack, &temp2);
    if (error != CALC_NO_ERR) return error;
    switch (operand) {
        case '+':
            temp2 += temp1;
            break;
        case '-':
            temp2 -= temp1;
            break;
        case '*':
            temp2 *= temp1;
            break;
        case '/':
            temp2 /= temp1;
            break;
        case '^':
            temp2 = pow(temp2, temp1);
            break;
        default:
            return CALC_NO_SUCH_OPERAND;
            break;
    }
    error = (CALC_ERR_TYPE) pushData(stack, &temp2);
    return error;
}

CALC_ERR_TYPE calculate (FILE *FilePtr, stack_element_type *result) {
    if (FilePtr == NULL) return CALC_NULL_POINTER;
    CALC_ERR_TYPE error = CALC_NO_ERR;
    
    stack_type calcStack;
    initializeStack(&calcStack);

    int temp = getc(FilePtr);
    
    stack_element_type value = 0;
    
    while (temp != EOF) {
        if ('0' <= temp && temp <= '9'){
            ungetc(temp, FilePtr);
            fscanf(FilePtr, "%lf", &value);
            error = (CALC_ERR_TYPE) pushData(&calcStack, &value);
        } else {
            if (temp != ' ' && temp != '\n')
                error = makeOperation(temp, &calcStack);
        }
        if (error != CALC_NO_ERR) {
            errorPrinter(error);
            return error;
        }
        temp = getc(FilePtr);
    }
    
    error = (CALC_ERR_TYPE) popData(&calcStack, result);
    
    if (error != CALC_NO_ERR) {
        errorPrinter(error);
        return error;
    }
    
    return CALC_NO_ERR;
}

void errorPrinter (CALC_ERR_TYPE error) {
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
        case 4:
            printf("Stack Nullptr\n");
            break;
        case 5:
            printf("Calc Nullptr");
            break;
        case 6:
            printf("Bad Operand");
            break;
        default:
            break;
    }
}
