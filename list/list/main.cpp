//
//  main.cpp
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "list.h"

int main(int argc, const char * argv[]) {
    List x;
    for (int i = 0; i < 500000; i++) {
        x.push_front(i);
        x.push_back(i);
    }
    
    for (long long i = 0; i < x.size(); i++) {
        std::cout << x[i] << std::endl;
    }
    std::cout << "front: " << x.front() << " back: " << x.back() << std::endl;
    for (int i = 0; i < 10000; i++) {
        std::cout << "front: " << x.front() << std::endl;
        x.pop_front();
    }
    for (int i = 0; i < 10000; i++) {
        std::cout << "back: " << x.back() << std::endl;
        x.pop_back();
    }
    
    if (x.empty()) std::cout << "empty" << std::endl;
    else std::cout << "not empty" << std::endl;
    
    x.clear();
    
    if (x.empty()) std::cout << "now it is empty" << std::endl;
    else std::cout << "not empty" << std::endl;
    
    for (int i = 0; i < 6; i++) {
        x.push_back(i);
    }
    
    int a = 10;
    x.insert(3, a);
    
    for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }
    
    List x1; //= x;
    
    x1 = x;
    
    std::cout << "\n Now new List x1" << std::endl;
    
    for (int i = 0; i < x.size(); i++) {
        std::cout << x1[i] << " ";
    }
    
    std::cout << "\nended testing\n";
    x.clear();
    return 0;
}
