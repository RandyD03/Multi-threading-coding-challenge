# Multi-threading Coding-Challenge

This is a coding question. You may use C, or C++. 

You are to design and implement a basic message passing library for an embedded system. In this
system you should assume there are multiple threads, each with a unique identifier. These threads
should be able to use your message passing library to send and receive messages to and from other
threads. The message passing library is responsible for managing the memory associated with the
messages. The messages themselves are a simple structure as defined below:

![image](https://user-images.githubusercontent.com/105885340/204096449-2e1268ec-e6e3-42df-bbbe-cd457c0833c9.png)

Implement the message passing library using the following API:

a) `message_t* new_message()`:Threads call this function to get an available message
struct from the library. If the library is unable to provide a free message struct then this
function returns NULL.

b) `void delete_message(message_t* msg)`: Threads call this function to return a
message struct back to the message library. After calling delete_message the thread
will no longer use that message struct and the message library is free to give it out to
other threads that call new_message

c) `int send(uint8_t destination_id, message_t* msg)`: Threads may use this
function to send a message to another thread. The destination_id is the ID of the
thread the message should be delivered to and msg is the message to be delivered. A
response code should be returned where 0 indicates success and non-0 indicates an
error.

d) `int recv(uint8_t receiver_id, message_t* msg)`: Threads may use this
function to receive any pending incoming messages. The receiver_id is the ID of the
thread that wishes to receive a message. The msg argument is an output, and the
implementation of this function should set it to point to a message destined to
receiver_id if one exists. A response code should be returned where 0 indicates
success and non-0 indicates error.
![IMG_6717 (1)](https://user-images.githubusercontent.com/105885340/207221427-38a72baf-c5c9-4be3-85f9-b728c9181cb6.JPG)

