#pragma once

#include "msg_lib.h"    /* message_t */

struct List {
    struct Link *head;
    struct Link *tail;
    size_t length;
    pthread_t mutex;

};

struct Link {
    struct Link *next;
    message_t *msg;
};

struct List *init_list(struct List *me);
int list_push(struct List *me, message_t* msg);
message_t *list_pop(struct List *me);
