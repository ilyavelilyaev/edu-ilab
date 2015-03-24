//
//  main.h
//  Hash_Collision
//
//  Created by Ilya Velilyaev on 24.03.15.
//  Copyright (c) 2015 Ilya Velilyaev. All rights reserved.
//

#ifndef HASH_COLLISION_MAIN_H
#define HASH_COLLISION_MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cstdio>

#define BYTE_MAX 256

//list of errors
#define WRONG_USAGE 1


//end of list of errors

//classes definitions
class Word {
private:
    std::string str;
    unsigned char plus_hash;
    unsigned char xor_hash;
    unsigned char rotate_plus_hash;
    unsigned char rotate_xor_hash;
    void plusHashCalculation();
    void xorHashCalculation();
    void rotatePlusHashCalculation();
    void rotateXorHashCalculation();
    unsigned char rotate(unsigned char ch);
public:
    Word (std::string init_str);
    unsigned char getPlusHash();
    unsigned char getXorHash();
    unsigned char getRotatePlusHash();
    unsigned char getRotateXorHash();
};

class ReportTable {
private:
    unsigned long long *plus_hash_stats;
    unsigned long long *xor_hash_stats;
    unsigned long long *rotate_plus_hash_stats;
    unsigned long long *rotate_xor_hash_stats;
public:
    ReportTable();
    ~ReportTable();
    void addWord(Word word);
    void formReport(std::ofstream &output);
};
//end of classes definitions

//functions definitions
void print_help();
//end of functions definitions

#endif /* defined HASH_COLLISION_MAIN_H */
