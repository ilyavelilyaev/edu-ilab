//
//  assembler.cpp
//  Assembler
//
//  Created by Ilya Velilyaev on 15.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "assembler.h"

#define MAX_LINE_SIZE 256

std::string generateCodeLine (const std::string asmCode, int line) {
    std::size_t found_space = asmCode.find(' ');
    std::string temp_string;
    std::string argument;
    std::string result = "";
    if (found_space != std::string::npos) {
        argument = asmCode.substr(found_space + 1, asmCode.length() - 1);
        temp_string = asmCode.substr(0, found_space);
    } else
        temp_string = asmCode;
    
    if (temp_string.compare("PUSH") == 0 && found_space != std::string::npos) {
        char temp_c_str[10];
        if (argument[0] == 'A') {
            sprintf(temp_c_str, "%c", (char)PUSH_A_CODE);
        }
        if (argument[0] == 'B') {
            sprintf(temp_c_str, "%c", (char)PUSH_B_CODE);
        }
        if (argument[0] == 'C') {
            sprintf(temp_c_str, "%c", (char)PUSH_C_CODE);
        }
        if (argument[0] == 'D') {
            sprintf(temp_c_str, "%c", (char)PUSH_D_CODE);
        }
        if (('0' <= argument[0] && argument[0] <= '9') || (argument[0] == '-' && '0' <= argument[1] && argument[1] <= '9')) {
            double temp_double = 0;
            sscanf(argument.c_str(), "%lg", &temp_double);
            sprintf(temp_c_str, "%c%lg%c",(char)PUSH_CODE, temp_double, (char)END_OF_INPUT);
        }
        result = temp_c_str;
        return result;
    }
    bool popped = false;
    if (temp_string.compare("POP") == 0 && found_space != std::string::npos) {
        char temp_c_str[10];
        if (argument[0] == 'A') {
            sprintf(temp_c_str, "%c", (char)POP_A_CODE);
            popped = true;
        }
        if (argument[0] == 'B') {
            sprintf(temp_c_str, "%c", (char)POP_B_CODE);
            popped = true;
        }
        if (argument[0] == 'C') {
            sprintf(temp_c_str, "%c", (char)POP_C_CODE);
            popped = true;
        }
        if (argument[0] == 'D') {
            sprintf(temp_c_str, "%c", (char)POP_D_CODE);
            popped = true;
        }
        if (popped)
            result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("POP") == 0 && popped == false) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)POP_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("ADD") == 0){
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)ADD_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("SUB") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)SUB_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("MUL") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)MUL_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("DIV") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)DIV_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("NEG") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)NEG_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("INC") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)INC_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("DEC") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)DEC_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("SQRT") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)SQRT_CODE);
        result = temp_c_str;
        return result;
    }
    
    std::size_t found_colon = asmCode.find(':');
    
    if (found_colon != std::string::npos) {
        temp_string = asmCode.substr(0, found_colon);
        char temp_c_str[100];
        sprintf(temp_c_str, "%c%s%c", (char)MARK_CODE, temp_string.c_str(), (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JMP") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JMP_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JEA") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JEA_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JEB") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JEB_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JEC") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JEC_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JED") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JED_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JNEA") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JNEA_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JNEB") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JNEB_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JNEC") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JNEC_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("JNED") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)JNED_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("CALL") == 0 && found_space != std::string::npos) {
        char temp_c_str[100];
        char temp_argument_mark[100];
        sscanf(argument.c_str(), "%s", temp_argument_mark);
        sprintf(temp_c_str, "%c%s%c", (char)CALL_CODE, temp_argument_mark, (char)END_OF_INPUT);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("PRINT") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)PRINT_CODE);
        result = temp_c_str;
        return result;
    }

    
    if (temp_string.compare("RET") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)RET_CODE);
        result = temp_c_str;
        return result;
    }
    
    if (temp_string.compare("END") == 0) {
        char temp_c_str[10];
        sprintf(temp_c_str, "%c", (char)END);
        result = temp_c_str;
        return result;
    }
    return result;
    
}

void assemble(std::ifstream &input_file, const char* output_file_name) {
    std::ofstream output_file;
    output_file.open(output_file_name);
    int line = 0;
    while (!input_file.eof()) {
        char temp[MAX_LINE_SIZE];
        input_file.getline(temp, MAX_LINE_SIZE);
        std::string temp_string = temp;
        std::size_t found_semicolon = temp_string.find(';');
        temp_string = temp_string.substr(0, found_semicolon);
        output_file << generateCodeLine(temp_string, line);
        line ++;
    }
    output_file.close();
}
