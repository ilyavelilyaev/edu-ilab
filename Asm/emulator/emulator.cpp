//
//  Emulator.cpp
//  Emulator
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "Emulator.h"

Processor::Processor() {
    regA = 0;
    regB = 0;
    regC = 0;
    regD = 0;
    commands = "";
}

void Processor::setRegA(double &a) {
    regA = a;
}
void Processor::setRegB(double &a) {
    regB = a;
}
void Processor::setRegC(double &a) {
    regC = a;
}
void Processor::setRegD(double &a) {
    regD = a;
}

void Processor::setCommands(std::ifstream &input_file) {
    while (!input_file.eof()) {
        commands += (char)input_file.get();
    }
}

double Processor::getRegA() {
    return regA;
}

double Processor::getRegB() {
    return regB;
}

double Processor::getRegC() {
    return regC;
}

double Processor::getRegD() {
    return regD;
}

void Processor::decode(int &pos) {
    if (commands[pos] == PUSH_CODE) {
        std::string pushing_value = "";
        pos++;
        
        if (commands[pos] == END_OF_INPUT)
            throw "NOTHING TO PUSH";
        
        while (commands[pos] != END_OF_INPUT) {
            pushing_value += commands[pos];
            pos++;
        }
        double push_val = 0;
        sscanf(pushing_value.c_str(), "%lg", &push_val);
        proc_stack.push(push_val);
        return;
    }
    if (commands[pos] == PUSH_A_CODE) {
        proc_stack.push(regA);
        return;
    }
    if (commands[pos] == PUSH_B_CODE) {
        proc_stack.push(regB);
        return;
    }
    if (commands[pos] == PUSH_C_CODE) {
        proc_stack.push(regC);
        return;
    }
    if (commands[pos] == PUSH_D_CODE) {
        proc_stack.push(regD);
        return;
    }
    if (commands[pos] == POP_CODE) {
        proc_stack.pop();
        return;
    }
    if (commands[pos] == POP_A_CODE) {
        setRegA(proc_stack.top());
        proc_stack.pop();
        return;
    }
    if (commands[pos] == POP_B_CODE) {
        setRegB(proc_stack.top());
        proc_stack.pop();
        return;
    }
    if (commands[pos] == POP_C_CODE) {
        setRegC(proc_stack.top());
        proc_stack.pop();
        return;
    }
    if (commands[pos] == POP_D_CODE) {
        setRegD(proc_stack.top());
        proc_stack.pop();
        return;
    }
    if (commands[pos] == ADD_CODE) {
        double temp = 0;
        temp = proc_stack.top();
        proc_stack.pop();
        temp += proc_stack.top();
        proc_stack.pop();
        proc_stack.push(temp);
        return;
    }
    if (commands[pos] == SUB_CODE) {
        double temp1 = 0, temp2 = 0;
        temp1 = proc_stack.top();
        proc_stack.pop();
        temp2 = proc_stack.top();
        proc_stack.pop();
        temp2 -= temp1;
        proc_stack.push(temp2);
        return;
    }
    if (commands[pos] == MUL_CODE) {
        double temp = 0;
        temp = proc_stack.top();
        proc_stack.pop();
        temp *= proc_stack.top();
        proc_stack.pop();
        proc_stack.push(temp);
        return;
    }
    if (commands[pos] == DIV_CODE) {
        double temp1 = 0, temp2 = 0;
        temp1 = proc_stack.top();
        proc_stack.pop();
        temp2 = proc_stack.top();
        proc_stack.pop();
        if (temp1 == 0)
            throw "DIVISION BY ZERO";
        temp2 /= temp1;
        proc_stack.push(temp2);
        return;
    }
    if (commands[pos] == NEG_CODE) {
        double temp = 0;
        temp = proc_stack.top();
        proc_stack.pop();
        temp = -temp;
        proc_stack.push(temp);
        return;
    }
    if (commands[pos] == INC_CODE) {
        double temp = 0;
        temp = proc_stack.top();
        proc_stack.pop();
        temp ++;
        proc_stack.push(temp);
        return;
    }
    if (commands[pos] == DEC_CODE) {
        double temp = 0;
        temp = proc_stack.top();
        proc_stack.pop();
        temp --;
        proc_stack.push(temp);
        return;
    }
    if (commands[pos] == SQRT_CODE) {
        double temp = 0;
        temp = proc_stack.top();
        proc_stack.pop();
        if (temp < 0)
            throw "CAN'T TAKE SQUARE ROOT FROM NEGATIVE VALUE";
        temp = sqrt(temp);
        proc_stack.push(temp);
        return;
    }
    if (commands[pos] == JMP_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";

        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        pos = found;
        return;
    }
    if (commands[pos] == JEA_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() == regA)
            pos = found;
        return;
    }
    if (commands[pos] == JEB_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() == regB)
            pos = found;
        return;
    }
    if (commands[pos] == JEC_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() == regC)
            pos = found;
        return;
    }
    if (commands[pos] == JED_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() == regD)
            pos = found;
        return;
    }
    if (commands[pos] == JNEA_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() != regA)
            pos = found;
        return;
    }
    if (commands[pos] == JNEB_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() != regB)
            pos = found;
        return;
    }
    if (commands[pos] == JNEC_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() != regC)
            pos = found;
        return;
    }
    if (commands[pos] == JNED_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO JUMP";
        
        if (proc_stack.top() != regD)
            pos = found;
        return;
    }
    if (commands[pos] == PRINT_CODE) {
        std::cout << proc_stack.top() << std::endl;
    }
    if (commands[pos] == CALL_CODE) {
        std::string temp_mark = "";
        pos++;
        if (commands[pos] == END_OF_INPUT)
            throw "NO ARGUMENT TO JUMP";
        
        while (commands[pos] != END_OF_INPUT) {
            temp_mark += commands[pos];
            pos++;
        }
        int found = (int) commands.find(temp_mark);
        
        if (found == std::string::npos)
            throw "DID NOT FOUND SUCH MARK TO CALL";
        
        funcs.push(pos);
        pos = found;
        return;
    }
    if (commands[pos] == RET_CODE) {
        pos = funcs.top();
        return;
    }
    if (commands[pos] == MARK_CODE) {
        return;
    }
    
    
}

void Processor::emulate () {
    int pos = 0;
    while (commands[pos] != END) {
        decode(pos);
        pos++;
    }
}

Processor::~Processor() {
    
}
