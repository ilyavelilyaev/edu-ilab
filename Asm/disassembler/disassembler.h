//
//  disassembler.h
//  Disassembler
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <iostream>
#include <fstream>

#include "../codes.h"

void disassemble(std::ifstream &input_file, const char* output_file_name);

#endif /* defined(DISASSEMBLER_H) */
