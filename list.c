#include <pthread.h>

#include "list.h"

struct List *init_list(struct List *me) {
    me->head = NULL;
    me->tail = NULL;
    me->length = 0;
    pthread_mutex_init(&me->mutex, NULL);
    return me;
}

int list_push(struct List *me, message_t* msg) {
    pthread_mutex_lock(&me->mutex);
    /* TODO DO THIS */
    pthread_mutex_unlock(&me->mutex);
}

message_t *list_pop(struct List *me) {
    pthread_mutex_lock(&me->mutex);
    /* TODO DO THIS */
    pthread_mutex_unlock(&me->mutex);
}