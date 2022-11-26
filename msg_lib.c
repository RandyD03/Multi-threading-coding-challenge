#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include <pthread.h>


#include "msg_lib.h"
#include "list.h"


struct List msg_queues[255];

message_t *new_message() {
    return (message_t *)malloc(sizeof(message_t));
}

void delete_message(message_t *msg) {
    free(msg);
}

int send(uint8_t destination_id, message_t *msg) {
    list_push(&msg_queues[destination_id], msg);
}

int recv(uint8_t receiver_id, message_t *msg) {
    msg = list_pop(&msg_queues[receiver_id]);
}

