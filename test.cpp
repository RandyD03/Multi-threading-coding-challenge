/*

TEST FILE

CREATED BY RANDY DING

*/

#include "globals.hpp"

#include <iostream>
using namespace std;

List msg_queues[NUM_THREAD_QUEUES];

void thread_function(uint8_t home_id, uint8_t send_id, uint8_t message); // usage: msg_queues[home_id] and msg_queues[send_id]

int main() {

    //insert any threads you want to create
    std::thread threadobj0(thread_function, 0, 2, 100);
    std::thread threadobj1(thread_function, 1, 2, 200);
    std::thread threadobj2(thread_function, 2, 0, 300);
    std::thread threadobj3(thread_function, 3, 2, 400);

    //join all threads here
    threadobj0.join();
    threadobj1.join();
    threadobj2.join();
    threadobj3.join();
    return 0;
}

//test function to send and recieve msg
void thread_function(uint8_t home_id, uint8_t send_id, uint8_t message) {

    //send a message
    message_t* msg = new_message();
    if(msg != nullptr) {
        //data sent: {message, id of sender}
        msg->data[0] = message;
        msg->data[1] = home_id;
        msg->len = 2;   //only store 2 elements for this test case
        send(send_id, msg); 
        std::cout << "message from thread " << (int)home_id << " sent" << endl;
    }
    else std::cout << "message from thread " << (int)home_id << " not sent" << endl;

    //buffer
    for(int i = 0; i < 100000000; i++);

    //print recieved messages
    message_t* m;
    int iterator = msg_queues[home_id].length;
    for(int i = 0; i < iterator; i++) {
        try {
            int status = recv(home_id, m);
            if(status == 1) throw 1; //status code 0: success
            cout << "thread " << (int)home_id << " data: " << (int)m->data[0] << " from " << (int)m->data[1] << endl;
        }
        catch(int error) {
            cout << "recieving error in thread " << home_id << " with code " << error << endl;
        }

    }
    cout << "thread " << (int)home_id << " done" << endl;
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