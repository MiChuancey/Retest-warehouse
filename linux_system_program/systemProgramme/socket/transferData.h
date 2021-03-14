//
// Created by Administrator on 2021/3/14.
//

#ifndef SOCKET_TRANSFERDATA_H
#define SOCKET_TRANSFERDATA_H

#define NAMELEN 50
#define MSGLEN 1024
#define SERPORT 5555

struct MSG {
    u_int32_t ip;
    u_int16_t port;
    char name[NAMELEN];
    char msg[MSGLEN];
}__attribute__((packed));

#endif //SOCKET_TRANSFERDATA_H
