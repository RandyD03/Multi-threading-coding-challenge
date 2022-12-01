#include "msg_lib.h"
#include "link.h"

Link::Link(message_t* newmsg) {
    next = nullptr;
    msg = newmsg;
}

