//
//  listExeptions.cpp
//  list
//
//  Created by Ilya Velilyaev on 06.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "listExeptions.h"

const char *list_empty::what() const throw () {
    return "ERROR!! List is Empty\n";
}

const char *out_of_size::what() const throw () {
    return "ERROR!! Out of size\n";
}

const char *no_such_filetype::what() const throw () {
    return "ERROR!! Unknown filetype\n";
}
