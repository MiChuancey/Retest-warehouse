//
// Created by Administrator on 2021/3/18.
//

#ifndef TEST_INIT_H
#define TEST_INIT_H

#include "logParamenters.h"
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct nic_struct {
    char nic_name[NIC_SIZE]; // network interface card name
    uint8_t nic_MAC[ETHER_ADDR_LEN]; // network interface card MAC address
    struct in_addr ipaddr; // ip address
    struct in_addr netmask; // network mask
    struct in_addr gateway;
    struct in_addr dns;
} NIC_STRUCT;


static void showUsage();
static void initArgument(const int*,char***);
static void initLoginConfig();
static void initDevice();

#endif //TEST_INIT_H
