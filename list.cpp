#include "msg_lib.hpp"
#include "link.hpp"
#include "list.hpp"

#include <new>

//constructor
List::List() { //creates datapath for thread
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int list_push(List* dest, message_t* msg) {   // pushes msg to another thread
    
    try {
        if(dest->length == 0) {

            dest->lock.lock();
            dest->head = new Link(msg);
            dest->tail = dest->head;
            dest->length = 1;
            dest->lock.unlock();
            return 0;
        }
        else {

        dest->lock.lock();
        dest->tail->next = new Link(msg);
        dest->tail = dest->tail->next;
        dest->length++;
        dest->lock.unlock();
        return 0;
        }
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
            length--;
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