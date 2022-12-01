#include "globals.h"
#include <iostream>
using namespace std;

extern List msg_queues[255];

void thread_function(uint8_t queue_id); // msg_queues[queue_id]

int main() {

    std::thread threadobj1(thread_function,1);
    // std::thread threadobj2(thread_function,2);
    // std::thread threadobj3(thread_function,3);

    threadobj1.join();
    // threadobj2.join();
    // threadobj3.join();
    return 0;
}

void thread_function(uint8_t queue_id) {
    for(int i = 0; i < 4 /*create 4 messages*/; i++) {
        message_t* msg = new_message();
        if(new_message != nullptr) {
            msg->data[0] = i;
            msg->len = 1;   //only store one element for this test case
            send(queue_id + 1, msg); 
        }

        //print output
        cout << "thread " << queue_id << "data: " << endl;
        for(int i = 0; i < msg_queues[queue_id].head->msg->len; i++) {
            message_t* m;

            try {
                int status = recv(queue_id, m);
                if(status == 1) throw 1;
            }
            catch(int num) {
                cout << "bad recieve" << endl;
            }
            
            for(int j = 0; j < m->len; j++) {
                cout << m->data[j];
            }
        }
        cout << "end" << endl << endl;
    }
}