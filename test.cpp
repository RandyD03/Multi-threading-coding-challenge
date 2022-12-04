#include "globals.h"

#include <iostream>
using namespace std;

extern List msg_queues[255];

void thread_function0(uint8_t queue_id); // msg_queues[queue_id]
void thread_function1(uint8_t queue_id); // msg_queues[queue_id]

int main() {

    std::thread threadobj1(thread_function0,0);
    std::thread threadobj2(thread_function1,1);

    threadobj1.join();
    threadobj2.join();
    return 0;
}

//test function to randomly send and recieve msg
void thread_function0(uint8_t queue_id) {
        message_t* msg = new_message();
        if(new_message != nullptr) {
            msg->data[0] = 0;
            msg->len = 1;   //only store one element for this test case
            send(1, msg); 
            std::cout << "thread 0 sent" << endl;
        }
        else std::cout << "thread 0 not sent" << endl;

        //print output
        std::cout << "thread " << queue_id << "data: " << endl;
        for(int i = 0; i < 10000; i++);
        message_t* m;
        cout << (int)m->data[1] << endl;
        int status = recv(queue_id, m);
        cout << (int)m->data[1] << endl;
        cout << status << endl;

        // for(int i = 0; i < msg_queues[queue_id].head->msg->len; i++) {
        //     message_t* m;

        //     try {
        //         int status = recv(queue_id, m);
        //         if(status == 1) throw 1;
        //     }
        //     catch(int num) {
        //         std::cout << "bad recieve" << endl;
        //     }
            
        //     for(int j = 0; j < m->len; j++) {
        //         std::cout << m->data[j];
        //     }
        // }
        std::cout << "end 0" << endl << endl;
}

void thread_function1(uint8_t queue_id) {
        message_t* msg = new_message();
        if(new_message != nullptr) {
            msg->data[0] = 1;
            msg->len = 1;   //only store one element for this test case
            send(0, msg); 
            std::cout << "thread 1 sent" << endl;
        }
        else std::cout << "thread 1 not sent" << endl;
        //print output
        std::cout << "thread " << queue_id << "data: " << endl;

        for(int i = 0; i < 10000; i++);
        message_t* m;
        cout << (int)m->data[0] << endl;
        int status = recv(queue_id, m);
        cout << (int)m->data[0] << endl;
        cout << status << endl;

        // for(int i = 0; i < msg_queues[queue_id].head->msg->len; i++) {
        //     message_t* m;

        //     try {
        //         int status = recv(queue_id, m);
        //         if(status == 1) throw 1;
        //     }
        //     catch(int num) {
        //         std::cout << "bad recieve" << endl;
        //     }
            
        //     for(int j = 0; j < m->len; j++) {
        //         std::cout << m->data[j];
        //     }
        // }
        std::cout << "end 1" << endl << endl;
}