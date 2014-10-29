//
//  list.h
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef LIST_H
#define LIST_H


enum LIST_ERR_TYPE {
    NO_ERR,
    
};

class data {
    
};

class list {
    list();
    data *array;
    list *next;
    list *prev;
    ~list();
};


#endif
