//
//  main.cpp
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include <iostream>
#include "list.h"

int main(int argc, const char * argv[]) {
    List x;
    Type a;
    
    for (long long i = 0; i<=10000000; i++){
        if (i % 1000 == 0) std::cout << i << std::endl;
        a.number = i;
        x.push(&a);
    }

    return 0;
}
