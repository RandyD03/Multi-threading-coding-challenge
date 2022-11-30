#include <msg_lib.h>
#include <list.h>


List msg_queues[255];   //each element can store one thread

message_t *new_message() {
    return new message_t;
}

void delete_message(message_t* msg) {
    delete msg;
}

int send(uint8_t destination_id, message_t* msg) {
    list_push(&msg_queues[destination_id],msg);
}

int recv(uint8_t receiver_id, message_t* msg) { //reciever_id would be itself
    msg = list_pop(&msg_queues[receiver_id]);
}