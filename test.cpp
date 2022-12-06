/*TEST FILE
CREATED BY RANDY DING
*/

#include "globals.hpp"

#include <iostream>
using namespace std;

List msg_queues[NUM_THREAD_QUEUES];

void thread_function(uint8_t home_id, uint8_t recv_id, uint8_t message); // msg_queues[queue_id]

int main() {

    //insert any threads you want to create
    std::thread threadobj1(thread_function, 0, 1,100);
    std::thread threadobj2(thread_function, 1, 0,200);

    //join all threads here
    threadobj1.join();
    threadobj2.join();
    return 0;
}

//test function to send and recieve msg
void thread_function(uint8_t home_id, uint8_t send_id, uint8_t message) {
        message_t* msg = new_message();
        if(new_message != nullptr) {
            msg->data[0] = message;
            msg->len = 1;   //only store one element for this test case
            send(send_id, msg); 
            std::cout << "thread " << (int)home_id << " sent" << endl;
        }
        else std::cout << "thread " << (int)home_id << " not sent" << endl;

        //print output
        for(int i = 0; i < 10000; i++); // buffer
        message_t* m;
        int status = recv(home_id, m);
        cout << "thread " << (int)home_id << " data: " << (int)m->data[0] << endl;
        cout << "thread " << (int)home_id << " status: " << status << endl;
}




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