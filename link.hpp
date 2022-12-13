#ifndef LINK_HPP
#define LINK_HPP

#include "msg_lib.hpp"

class Link {
public:
    Link* next;
    message_t* msg;
    Link(message_t* newmsg);
};

#endif /*link_h*/