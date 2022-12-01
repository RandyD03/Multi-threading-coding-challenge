#ifndef MSG_LIB
#define MSG_LIB
#include<stdint.h>

typedef struct {
    uint8_t len;
    uint8_t data[255];
} message_t;

void create_list();
message_t *new_message();
void delete_message(message_t* msg);
int send(uint8_t destination_id, message_t* msg);
int recv(uint8_t receiver_id, message_t* msg);
#endif