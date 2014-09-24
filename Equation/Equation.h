//
//  Equation.h
//  Equation
//
//  Created by Ilya Velilyaev on 23.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define POWER_OF_EQUATION 2

#define ERROR_PRINT(a) ((a) ? 0 : printf("\nError\n%s in incorrect\nline:%d\n\n", #a, __LINE__));

enum ERR_ENUM_TYPE {
    NO_ERROR,
    NOT_AN_EQUATION,
    DISCRIMINANT_LESS_THAN_ZERO,
    FUNCTION_NOT_IMPLEMENTED,
    ENTERED_NOT_NUMBERS,
    NOT_EXACT_NUMBER_OF_FACTORS_ENTERED,
};


ERR_ENUM_TYPE solve1or2power (double *inp, double *answers, int length);
ERR_ENUM_TYPE solve (double *inp, double *answers, int length);
void cut_string (char *string);
void convert (char *string, double *inp, int length, unsigned long string_length);
ERR_ENUM_TYPE  delete_unwanted_spaces_check_convert (char *ENTERED_STRING, double *inp, int length);
ERR_ENUM_TYPE input (double *inp, int length);
void output (double *answers, int length);
ERR_ENUM_TYPE sort (double *answers, int length);
int repeat();
ERR_ENUM_TYPE run(double *inp, double *answers, int length);
void error_printer (ERR_ENUM_TYPE error);
int main();

#endif

