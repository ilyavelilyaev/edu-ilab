//
//  listExeptions.h
//  list
//
//  Created by Ilya Velilyaev on 06.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef LISTEXEPTIONS
#define LISTEXEPTIONS

#include <exception>

class list_empty : public std::exception {
public:
    const char *what() const throw ();
};

class out_of_size : public std::exception {
public:
    const char *what() const throw ();
};

class no_such_filetype : public std::exception {
public:
    const char *what() const throw ();
};

#endif /* defined(LISTEXEPTIONS) */
