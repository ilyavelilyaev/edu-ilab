//
//  main.cpp
//  Calculator
//
//  Created by Ilya Velilyaev on 27.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "calc.h"

#define FILE_NAME_PATH "./input.txt"

int main() {
    FILE *filePtr;
    filePtr = fopen(FILE_NAME_PATH, "r");
    stack_element_type result = 0;
    calculate(filePtr, &result);
    printf("%lf\n", result);
    fclose(filePtr);
    return 0;
}