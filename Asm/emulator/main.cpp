//
//  main.cpp
//  Emulator
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "emulator.h"

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        std::cerr << "Bad arguments. Use format:\nemulator \"source\"\n";
        return -1;
    }
    std::ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Failed to open file. Please try again.\n";
        return -1;
    }
    Processor my_proc;
    my_proc.setCommands(input);
    input.close();
    my_proc.emulate();
    return 0;
}
