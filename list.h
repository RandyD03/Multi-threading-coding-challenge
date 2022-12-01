#ifndef LIST_H
#define LIST_H

#include "msg_lib.h"   /* message_t */
#include "link.h"
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
    List();
};
#endif