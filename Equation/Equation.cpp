//
//  Equation.cpp
//  Equation
//
//  Created by Ilya Velilyaev on 23.09.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "Equation.h"

ERR_ENUM_TYPE solve1or2power (double *inp, double *answers, int length) {
    if ((inp[0] == 0) && (inp[1] == 0)) {
        printf("%d line ",__LINE__);
        return NOT_AN_EQUATION;
    }
    else {
        if (inp[0] == 0) {
            answers[0] = 1;
            answers[1] = -inp[2]/inp[1];
        } else {
            double discriminant = inp[1] * inp[1] - 4 * inp[0] * inp [2];
            if (discriminant >= 0) {
                answers[0] = 2;
                answers[1] = (-inp[1] + sqrt(discriminant)) / (2 * inp[0]);
                answers[2] = (-inp[1] - sqrt(discriminant)) / (2 * inp[0]);
            } else {
                printf("%d line ",__LINE__);
                return DISCRIMINANT_LESS_THAN_ZERO;
            }
        }
    }
    return NO_ERROR;
}

ERR_ENUM_TYPE solve (double *inp, double *answers, int length) {
    if (POWER_OF_EQUATION > 2) {
        printf("%d line ",__LINE__);
        return FUNCTION_NOT_IMPLEMENTED;
    }
    else return solve1or2power(inp, answers, length);
    return NO_ERROR;
}

void cut_string (char *string) {
    char *strtemp = strchr(string, 32);
    if (strtemp) {
        for (int i = 0; i < strlen(strtemp) - 1; i++) {
            string[i] = strtemp[i + 1];
        }
    }
}

void convert (char *string, double *inp, int length, unsigned long string_length) {
    for (int i = 0; i < length; i++) {
        sscanf(string, "%lg", &inp[i]);
        cut_string(string);
    }
}

ERR_ENUM_TYPE  delete_unwanted_spaces_check_convert (char *ENTERED_STRING, double *inp, int length) {
    char strtemp[256] = "";
    int k = 0;
    for (int i = 0; i < strlen(ENTERED_STRING) - 1; i++) {
        if (!(ENTERED_STRING[i] == ' ' && ENTERED_STRING[i - 1] == ' ')) {
            strtemp[k] = ENTERED_STRING[i];
            k++;
        }
    }
    
    k--;
    
    while (strtemp[k] == ' ') {
        strtemp[k] = 0;
        k--;
    }
    
    ENTERED_STRING = strtemp;
    
    int COUNT_OF_ENTERED_FACTORS = 1;
    
    for (int i = 0; i < strlen(ENTERED_STRING) - 1; i++) {
        if ((ENTERED_STRING[i] < 48 || ENTERED_STRING[i] > 57) && ENTERED_STRING[i] != 46 && ENTERED_STRING[i] != 32 && ENTERED_STRING[i] != '-') {
            printf("%d line ",__LINE__);
            return ENTERED_NOT_NUMBERS;
        } //symbol is not equal to number, space and dot
        
        if (ENTERED_STRING[i] == 32) COUNT_OF_ENTERED_FACTORS ++;
    }
    
    if (COUNT_OF_ENTERED_FACTORS != length) {
        printf("%d line ",__LINE__);
        return NOT_EXACT_NUMBER_OF_FACTORS_ENTERED;
    }
    convert(ENTERED_STRING, inp, length, strlen(ENTERED_STRING));
    
    return NO_ERROR;

}

ERR_ENUM_TYPE input (double *inp, int length) {
    printf("Enter factors a, b, c in equation of form ax^2 + bx + c = 0\n");
    
    char ENTERED_STRING[256];
    char temp[256], temp2[256];
    scanf("%s",temp);
    fgets (temp2, 256, stdin);
    strcpy(ENTERED_STRING, temp);
    strcat(ENTERED_STRING, temp2);

    return delete_unwanted_spaces_check_convert(ENTERED_STRING, inp, length);
}

void output (double *answers, int length) {
    if (answers[0] != 0) {
        if (answers[1] == 0) answers[1] = 0;
        printf("%lg\n", answers[1]);
        for (int i = 2; i < answers[0] + 1; i++) {
            if (answers[i] != answers[i - 1]) {
                if (answers[i] == 0) answers[i] = 0;
                printf("%lg\n", answers[i]);
            }
        }
    }
}

ERR_ENUM_TYPE sort (double *answers, int length) {
    double *answersSorted = answers;
    if (answers[0] > 1) {
        for(int x = 1; x < answers[0] + 1; x++) {
            for(int y=1; y < answers[0]; y++) {
                if(answersSorted[y]>=answersSorted[y+1]) {
                    double temp = answersSorted[y+1];
                    answersSorted[y+1] = answersSorted[y];
                    answersSorted[y] = temp;
                }
            }
        }
    }
    
    
    answersSorted[0] = answers[0];
    answers = answersSorted;
    return NO_ERROR;
}

int repeat() {
    bool WILL_REPEAT = true;
    char ENTERED_STRING[256] = "";
    char temp[256] = "";
    char temp2[256] = "";
    while ((ENTERED_STRING[0] != 'y' && ENTERED_STRING[0] != 'n') || strlen(ENTERED_STRING) != 2) {
        printf("Do you want to solve one more equation? \n (y/n) \n");
        scanf("%s", temp);
        fgets (temp2, 256, stdin);
        strcpy(ENTERED_STRING, temp);
        strcat(ENTERED_STRING, temp2);
        if (ENTERED_STRING[0] == 'y' && strlen(ENTERED_STRING) == 2)    WILL_REPEAT = true;
        if (ENTERED_STRING[0] == 'n' && strlen(ENTERED_STRING) == 2)    WILL_REPEAT = false;
    }
    return WILL_REPEAT;
}

ERR_ENUM_TYPE run(double *inp, double *answers, int length) {
    ERR_ENUM_TYPE INPUT_ERROR = NO_ERROR, SOLVE_ERROR = NO_ERROR, SORT_ERROR = NO_ERROR;
    
    INPUT_ERROR = input(inp, length);
    if (INPUT_ERROR != NO_ERROR) {
        return INPUT_ERROR;
    }
    
    SOLVE_ERROR = solve(inp, answers, length);
    if (SOLVE_ERROR != NO_ERROR) {
        return SOLVE_ERROR;
    }
    
    SORT_ERROR = sort(answers, length);
    if (SORT_ERROR != NO_ERROR) {
        return SORT_ERROR;
    }
    
    output(answers, length);
    
    return NO_ERROR;
}

void error_printer (ERR_ENUM_TYPE error) {
    switch (error) {
        case 0:
            break;
        case 1:
            printf("What you have entered is not an equation\n");
            break;
        case 2:
            printf("Discriminant is less than zero\n");
            break;
        case 3:
            printf("Function for solving equations with power more than 2 is not implemented\n");
            break;
        case 4:
            printf("You have not entered numbers\n");
            break;
        case 5:
            printf("You have entered too many/too little factors. You should enter %d factors\n", POWER_OF_EQUATION + 1);
            break;
    }
}

int main() {
    bool WILL_REPEAT = true;
    int len = POWER_OF_EQUATION + 1;
    ERR_ENUM_TYPE error = NO_ERROR;
    double inp[len];
    double answers[len];
    
    while (WILL_REPEAT) {
        error = run(inp, answers, len);
        
        if (error != NO_ERROR) {
            printf("ERROR!\n");
            error_printer(error);
        }
        
        WILL_REPEAT = repeat();
    }
    return 0;
}