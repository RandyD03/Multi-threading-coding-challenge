#include "msg_lib.hpp"
#include "link.hpp"

Link::Link(message_t* newmsg) {
    next = nullptr;
    msg = newmsg;
}

