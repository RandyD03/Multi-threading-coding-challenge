#include "msg_lib.h"
#include "link.h"
#include "list.h"
#include <new>

extern List msg_queues[255];

message_t *new_message() {
    try {
        message_t* new_message = new message_t;
        return new_message;
    }
    catch (const std::bad_alloc& e){
        return nullptr;
    }
    
}

void delete_message(message_t* msg) {
    delete msg;
}

int send(uint8_t destination_id, message_t* msg) {
    return list_push(&msg_queues[destination_id], msg);
}

int recv(uint8_t receiver_id, message_t* msg) { //reciever_id would be itself
    msg = msg_queues[receiver_id].list_pop();
    if(msg == nullptr) return 1;
    return 0;
}