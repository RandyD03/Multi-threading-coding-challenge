#ifndef LIST_H
#define LIST_H

#include "list.h"

#include <stdlib.h>
#include <mutex>
#include <thread>

class List {
public:
    Link* head;
    Link* tail;
    size_t length;
    std::mutex lock;    // each list has their own lock because multiple locks may be in use at the same time
    message_t* list_pop();

    //constructor
    List();
};

int list_push(List* dest, message_t* msg);

#endif /*list_h*/