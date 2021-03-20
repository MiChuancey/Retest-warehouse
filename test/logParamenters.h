//
// Created by Administrator on 2021/3/18.
//

#ifndef TEST_LOGPARAMENTERS_H
#define TEST_LOGPARAMENTERS_H

char *username;
char *password;
char *user_input_gateway; // 由用户设定的四个报文参数
char *user_input_dns;   // numbers-and-dots dns notation by user input
char *user_input_ipaddr;   // numbers-and-dots ip notation by user input
char *user_input_mask;   // number-and-dots mask notation by user input
char *service_company; // login service name
char *network_interface_card_name; // network interface card name
char *dev; // 连接的设备名

u_int background_running;
u_int exitFlag;

#endif //TEST_LOGPARAMENTERS_H
