#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "link.hpp"
#include "list.hpp"

#define NUM_THREAD_QUEUES 255
extern List msg_queues[NUM_THREAD_QUEUES];   //each element can store one thread

#endif /*globals_h*/