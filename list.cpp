#include <new>
#include "msg_lib.h"
#include "link.h"
#include "list.h"


//constructor
List::List() { //creates datapath for thread
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int list_push(List* dest, message_t* msg) {   // pushes msg to another thread
    
    try {
        dest->lock.lock();
        dest->tail->next = new Link(msg);
        dest->tail = dest->tail->next;
        dest->lock.unlock();
        return 0;
    }
    catch(const std::bad_alloc& e) {
        dest->lock.unlock();
        return 1;
    }
}

message_t* List::list_pop() { //pops from own list
    try {
        lock.lock();
        message_t* temp_msg;
        if(head != nullptr) {
            temp_msg = head->msg;
            Link* deleted_link = head;
            head->msg = nullptr;    //removes msg before deleting the Link
            head = head->next;
            delete deleted_link;
        }
        else {
            throw 0;
        }
        lock.unlock();
        return temp_msg;
    }
    catch(int num) {
        lock.unlock();
        return nullptr;
    }
}