//
//  disassembler.cpp
//  Disassembler
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "disassembler.h"
#include <exception>


void disassemble(std::ifstream &input_file, const char* output_file_name) {
    std::ofstream output_file;
    output_file.open(output_file_name);
    CODES temp_code = NO_CODE;
    std::string temp_string;
    input_file >> temp_string;
    char s[1000];
    strcpy(s, temp_string.c_str());
    sscanf(temp_string.c_str(), "%02d", &temp_code);
    temp_string.erase(0, 2);
    strcpy(s, temp_string.c_str());
    while (temp_code != END) {
        if (temp_code == PUSH_CODE) {
            int argument;
            sscanf(temp_string.c_str(), "%d!", &argument);
            char temp_arg_str[10];
            sprintf(temp_arg_str, "%d", argument);
            temp_string.erase(0, strlen(temp_arg_str) + 1);
            strcpy(s, temp_string.c_str());
            output_file << "PUSH " << argument << "\n";
        }
        if (temp_code == PUSH_A_CODE) {
            output_file << "PUSH A\n";
        }
        if (temp_code == PUSH_B_CODE) {
            output_file << "PUSH B\n";
        }
        if (temp_code == PUSH_C_CODE) {
            output_file << "PUSH C\n";
        }
        if (temp_code == PUSH_D_CODE) {
            output_file << "PUSH D\n";
        }
        if (temp_code == POP_CODE) {
            output_file << "POP\n";
        }
        if (temp_code == POP_A_CODE) {
            output_file << "POP A\n";
        }
        if (temp_code == POP_B_CODE) {
            output_file << "POP B\n";
        }
        if (temp_code == POP_C_CODE) {
            output_file << "POP C\n";
        }
        if (temp_code == POP_D_CODE) {
            output_file << "POP D\n";
        }
        if (temp_code == ADD_CODE) {
            output_file << "ADD\n";
        }
        if (temp_code == SUB_CODE) {
            output_file << "SUB\n";
        }
        if (temp_code == MUL_CODE) {
            output_file << "MUL\n";
        }
        if (temp_code == DIV_CODE) {
            output_file << "DIV\n";
        }
        if (temp_code == NEG_CODE) {
            output_file << "NEG\n";
        }
        if (temp_code == INC_CODE) {
            output_file << "INC\n";
        }
        if (temp_code == DEC_CODE) {
            output_file << "DEC\n";
        }
        if (temp_code == SQRT_CODE) {
            output_file << "SQRT\n";
        }
        if (temp_code == JMP_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JMP " << temp_mark << "\n";
        }
        if (temp_code == JEA_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JEA " << temp_mark << "\n";
        }
        if (temp_code == JEB_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JEB " << temp_mark << "\n";
        }
        if (temp_code == JEC_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JEC " << temp_mark << "\n";
        }
        if (temp_code == JED_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JED " << temp_mark << "\n";
        }
        if (temp_code == JNEA_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JNEA " << temp_mark << "\n";
        }
        if (temp_code == JNEB_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JNEB " << temp_mark << "\n";
        }
        if (temp_code == JNEC_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JNEC " << temp_mark << "\n";
        }
        if (temp_code == JNED_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "JNED " << temp_mark << "\n";
        }
        if (temp_code == PRINT_CODE) {
            output_file << "PRINT\n";
        }
        if (temp_code == CALL_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << "CALL " << temp_mark << "\n";
        }
        if (temp_code == RET_CODE) {
            output_file << "RET\n";
        }
        if (temp_code == MARK_CODE) {
            char temp_mark[100];
            int len = 0;
            do {
                sscanf(temp_string.c_str(), "%c", &temp_mark[len]);
                temp_string.erase(0,1);
                len++;
            } while (temp_mark[len - 1] != '!');
            len --;
            temp_mark[len] = 0;
            output_file << temp_mark << ":\n";
        }
        sscanf(temp_string.c_str(), "%02d", &temp_code);
        temp_string.erase(0, 2);
    }
    output_file << "END\n";
    output_file.close();
}
