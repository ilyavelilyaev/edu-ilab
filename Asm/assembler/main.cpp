//
//  main.cpp
//  Assembler
//
//  Created by Ilya Velilyaev on 15.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "assembler.h"

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cerr << "Bad arguments. Use format:\nassembler \"source\" \"output\"\n";
        return -1;
    }
    std::ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Failed to open file. Please try again.\n";
        return -1;
    }
    assemble(input, argv[2]);
    input.close();
    return 0;
}