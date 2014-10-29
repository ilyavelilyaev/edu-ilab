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
    double temp1 = 0, temp2 = 0;
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
            if (temp1 == 0) return CALC_DIVISION_BY_ZERO;
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

CALC_ERR_TYPE calculate (FILE *FilePtr, double *result) {
    if (FilePtr == NULL) return CALC_NULL_POINTER;
    CALC_ERR_TYPE error = CALC_NO_ERR;
    
    stack_type calcStack;
    initializeStack(&calcStack);

    int temp = getc(FilePtr);
    
    double value = 0;
    
    while (temp != EOF) {
        if ('0' <= temp && temp <= '9'){
            ungetc(temp, FilePtr);
            fscanf(FilePtr, "%lf", &value);
            error = (CALC_ERR_TYPE) pushData(&calcStack, &value);
        } else {
            if (temp == '-') {
                int temp2 = getc(FilePtr);
                ungetc(temp2, FilePtr);
                if ('0' <= temp2 && temp2 <= '9') {
                    ungetc(temp, FilePtr);
                    fscanf(FilePtr, "%lf", &value);
                    error = (CALC_ERR_TYPE) pushData(&calcStack, &value);
                } else error = makeOperation(temp, &calcStack);
            }
            if (temp != ' ' && temp != '\n' && temp != '-')
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
    destroyStack(&calcStack);
    
    return CALC_NO_ERR;

}

void errorPrinter (CALC_ERR_TYPE error) {
    printf("ERROR! (%d):\n", error);
    switch (error) {
        case STACK_NO_MEMORY:
            printf("There is no memmory to allocate stack\n");
            break;
        case STACK_STACK_FULL:
            printf("Stack is full\n");
            break;
        case STACK_STACK_EMPTY:
            printf("Stack is empty\n");
            break;
        case STACK_NULL_POINTER:
            printf("Stack Nullptr\n");
            break;
        case CALC_NULL_POINTER:
            printf("Calc Nullptr");
            break;
        case CALC_NO_SUCH_OPERAND:
            printf("Bad Operand");
            break;
        case CALC_DIVISION_BY_ZERO:
            printf("Divide by zero");
            break;
        default:
            break;
    }
}
