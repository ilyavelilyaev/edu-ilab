//
//  main.cpp
//  Hash_Collision
//
//  Created by Ilya Velilyaev on 24.03.15.
//  Copyright (c) 2015 Ilya Velilyaev. All rights reserved.
//

#include "main.h"




void print_help() {
    std::cout << "\nUsage: \t hash_collision <file> <report path>\n\n";
}


void Word::plusHashCalculation() {
    plus_hash = 0;
    unsigned int strlen = (unsigned int) str.length();
    for (int i = 0; i < strlen; i++) {
        plus_hash = (plus_hash + str[i]) % BYTE_MAX;
    }
}
void Word::xorHashCalculation() {
    xor_hash = 0;
    unsigned int strlen = (unsigned int) str.length();
    for (int i = 0; i < strlen; i++) {
        xor_hash = xor_hash xor str[i];
    }
}

unsigned char Word::rotate(unsigned char ch) {
    unsigned char temp[8];
    for (int i = 0; i < 8; i++) {
        temp[i] = (ch >> i) & 1;
    }
    unsigned char rotated = 0;
    int k = 0;
    for (int i = 2; i < 8; i++) {
        rotated += temp[i] << k;
        k++;
    }
    
    for (int i = 0; i < 3; i++) {
        rotated += temp[i] << k;
        k++;
    }
    return rotated;
}

void Word::rotatePlusHashCalculation() {
    rotate_plus_hash = 0;
    unsigned int strlen = (unsigned int) str.length();
    for (int i = 0; i < strlen; i++) {
        unsigned char ch = rotate(str[i]);
        rotate_plus_hash = (rotate_plus_hash + ch) % BYTE_MAX;
    }
}
void Word::rotateXorHashCalculation() {
    rotate_xor_hash = 0;
    unsigned int strlen = (unsigned int) str.length();
    for (int i = 0; i < strlen; i++) {
        unsigned char ch = rotate(str[i]);
        rotate_xor_hash = rotate_xor_hash xor ch;
    }
}

Word::Word (std::string init_str) : str(init_str) {
    plusHashCalculation();
    xorHashCalculation();
    rotatePlusHashCalculation();
    rotateXorHashCalculation();
}

unsigned char Word::getPlusHash() { return plus_hash; }
unsigned char Word::getXorHash() { return xor_hash; }
unsigned char Word::getRotatePlusHash() { return rotate_plus_hash; }
unsigned char Word::getRotateXorHash() { return rotate_xor_hash; }


ReportTable::ReportTable() {
    plus_hash_stats = new unsigned long long[BYTE_MAX];
    xor_hash_stats = new unsigned long long[BYTE_MAX];
    rotate_plus_hash_stats = new unsigned long long[BYTE_MAX];
    rotate_xor_hash_stats = new unsigned long long[BYTE_MAX];
    memset(plus_hash_stats, 0, BYTE_MAX);
    memset(xor_hash_stats, 0, BYTE_MAX);
    memset(rotate_plus_hash_stats, 0, BYTE_MAX);
    memset(rotate_xor_hash_stats, 0, BYTE_MAX);
}

ReportTable::~ReportTable() {
    delete [] plus_hash_stats;
    delete [] xor_hash_stats;
    delete [] rotate_plus_hash_stats;
    delete [] rotate_xor_hash_stats;
}

void ReportTable::addWord(Word word) {
    plus_hash_stats[word.getPlusHash()] ++;
    xor_hash_stats[word.getXorHash()] ++;
    rotate_plus_hash_stats[word.getRotatePlusHash()] ++;
    rotate_xor_hash_stats[word.getRotateXorHash()] ++;
}


void ReportTable::formReport(std::ofstream &output) {
    output << "Plus \t Xor \t Rotate Plus \t Rotate Xor \n";
    for (int c = 0; c < BYTE_MAX; c++) {
        output << c << "\t" << plus_hash_stats[c] << "\t" << xor_hash_stats[c] << "\t" << rotate_plus_hash_stats[c] << "\t" << rotate_xor_hash_stats[c] << "\n";
    }
}





int main(int argc, const char * argv[]) {
    if (argc != 3) {
        print_help();
        return WRONG_USAGE;
    }
    
    std::ifstream input_file;
    input_file.open(argv[1]);
    if (!input_file.is_open()) {
        std::cout << "Error occured while opening input file";
        print_help();
        return WRONG_USAGE;
    }
    
    std::ifstream in(argv[1], std::ifstream::ate | std::ifstream::binary);
    std::ifstream::pos_type size_of_file = in.tellg();
    in.close();
    
    std::ofstream output_file;
    output_file.open(argv[2]);
    if (!output_file.is_open()) {
        std::cout << "Error occured while opening output file";
        print_help();
        return WRONG_USAGE;
    }
    
    ReportTable reportTable;
    while (!input_file.eof()) {
        printf("\rReading file %s: [%3lld%%]", argv[1], input_file.tellg() * 100 / size_of_file);
        std::string temp;
        input_file >> temp;
        Word temp_word(temp);
        reportTable.addWord(temp_word);
    }
    printf("\rReading file %s: [100%%] \nReading ended. Creating Report...\n", argv[1]);
    
    reportTable.formReport(output_file);
    
    std::cout << "Creating of Report finished. You can find it in " << argv[2] << "\n";
    
    input_file.close();
    output_file.close();
    
    
    return 0;
}
