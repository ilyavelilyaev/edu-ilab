//
//  assembler.h
//  Assembler
//
//  Created by Ilya Velilyaev on 15.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "../codes.h"

void assemble(std::ifstream &input_file, const char* output_file_name);

std::string generateCodeLine (const std::string asmCode, int line);


#endif /* defined(ASSEMBLER_H) */
