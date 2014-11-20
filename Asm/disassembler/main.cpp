//
//  main.cpp
//  Disassembler
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "disassembler.h"

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cerr << "Bad arguments. Use format:\ndisassembler \"source\" \"output\"\n";
        return -1;
    }
    std::ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Failed to open file. Please try again.\n";
        return -1;
    }
    disassemble(input, argv[2]);
    input.close();
    return 0;
}
