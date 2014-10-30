//
//  list.cpp
//  list
//
//  Created by Ilya Velilyaev on 29.10.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#include "list.h"


List::List() {
    length = 0;
    head = NULL;
}

List::~List() {
    Node *node = NULL;
    if (head != NULL) node = head->next;
    Node *node1 = head;
    while (node != NULL) {
        free(node1);
        node1 = node;
        node = node->next;
    }
}

LIST_ERR_TYPE List::push(Type *newItem) {
    if (newItem == NULL) return NULL_POINTER;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = *newItem;
    if (head == NULL) {
        head = newNode;
        head->prev = NULL;
        head->next = NULL;
    } else {
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
    length++;
    return NO_ERR;
}

LIST_ERR_TYPE List::pop(Type *poppedItem) {
    if (poppedItem == NULL) return NULL_POINTER;
    if (length == 0) return EMPTY_LIST;
    *poppedItem = head->value;
    if (length > 1) {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    } else {
        free(head);
    }
    
    length--;
    return NO_ERR;
}
