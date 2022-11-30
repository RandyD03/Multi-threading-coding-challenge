#include "list.h"

//constructor
List::List() { //creates datapath for thread
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int list_push(List* dest, message_t* msg) {   // pushes msg to another thread

    dest->lock.lock();
    dest->tail->next = new Link(msg);
    dest->lock.unlock();
}

message_t* List::list_pop() { //pops from own list

    lock.lock();
    message_t* temp_msg = head->msg;
    Link* deleted_link = head;
    head->msg = nullptr;    //removes msg before deleting the Link
    head = head->next;
    delete deleted_link;
    return temp_msg;
    lock.unlock();
}