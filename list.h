#ifndef LIST.H
#define LIST.H

#include <msg_lib.h>   /* message_t */
#include <stdlib.h>

class List {
public:
    Link* head;
    Link* tail;
    size_t length;
    std::mutex lock;    // each list has their own lock because multiple locks may be in use at the same time

    int list_push(message_t* msg);
    message_t* list_pop();
};

class Link {
public:
    Link* next;
    message_t* msg;
};


#endif