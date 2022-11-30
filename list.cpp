#include <list.h>
#include <mutex>

List::List() { //creates datapath for thread
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int list_push(List* dest, message_t* msg) {   // pushes msg to another thread
    dest->lock.lock();

    dest->lock.unlock();
}

message_t* List::list_pop() { //pops from own list
    lock.lock();
    
    lock.unlock();
}