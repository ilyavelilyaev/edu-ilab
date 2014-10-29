//
//  calc.h
//  Calculator
//
//  Created by Ilya Velilyaev on 27.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef CALC_H
#define CALC_H

#include <math.h>
#include "stack.h"


enum CALC_ERR_TYPE {
    CALC_NO_ERR,
    STACK_NO_MEMORY,
    STACK_STACK_FULL,
    STACK_STACK_EMPTY,
    STACK_NULL_POINTER,
    CALC_NULL_POINTER,
    CALC_NO_SUCH_OPERAND,
    CALC_DIVISION_BY_ZERO,
};


CALC_ERR_TYPE calculate (FILE *FilePtr, stack_element_type *result);

void errorPrinter (CALC_ERR_TYPE error);

CALC_ERR_TYPE sum (stack_type *stack);
CALC_ERR_TYPE difference (stack_type *stack);
CALC_ERR_TYPE multiply (stack_type *stack);
CALC_ERR_TYPE divide (stack_type *stack);
CALC_ERR_TYPE power (stack_type *stack);

CALC_ERR_TYPE makeOperation (int operand, stack_type *stack);

#endif
