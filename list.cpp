#include <list.h>
#include <mutex>

List::List() { //creates datapath for thread
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int List::list_push(message_t* msg) {   // pushes msg to another thread
    lock.lock();

    lock.unlock();
}

message_t* List::list_pop() { //pops from own list
    lock.lock();
    
    lock.unlock();
}