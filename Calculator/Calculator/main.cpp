//
//  main.cpp
//  Calculator
//
//  Created by Ilya Velilyaev on 27.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "calc.h"
#include <errno.h>


int main(int argc, char *argv[]) {
    if (argc > 2) {
        printf("ERROR! Too many args\n");
        return 1; //too many args
    }
    if (argc < 2) {
        printf("ERROR! enter name of file in argument\n");
        return 2; //no args
    }
    FILE *filePtr;
    filePtr = fopen(argv[1], "r");
    if (filePtr == NULL) {
        perror("Error");
    }
    stack_element_type result = 0;
    CALC_ERR_TYPE error = calculate(filePtr, &result);
    if (error == CALC_NO_ERR) printf("%lf\n", result);
    fclose(filePtr);
    return 0;
}