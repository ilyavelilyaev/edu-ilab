//
//  Emulator.h
//  Emulator
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef EMULATOR_H
#define EMULATOR_H

#include <iostream>
#include <fstream>
#include "../stack/stack.h"
#include <cstdio>
#include "../codes.h"
#include <cmath>


class Processor {
private:
    double regA;
    double regB;
    double regC;
    double regD;
    std::string commands;
    Stack proc_stack;
    Stack funcs;
    void decode(int &pos);
public:
    Processor();
    
    void setRegA(double &a);
    void setRegB(double &a);
    void setRegC(double &a);
    void setRegD(double &a);
    void setCommands(std::ifstream &input_file);
    
    double getRegA();
    double getRegB();
    double getRegC();
    double getRegD();

    void emulate ();
    
    ~Processor();
};



#endif /* defined(EMULATOR_H) */
