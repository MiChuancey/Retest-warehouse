//
// Created by Administrator on 2021/3/15.
//

#ifndef MYTINYHTTPD_SERVERPARAMETER_H
#define MYTINYHTTPD_SERVERPARAMETER_H

const unsigned short SERVERPORT = 4444;
const int MAXCONNECTIONNUM = 10;
const int BUFFSIZE = 1024;
const int METHODSIZE = 255;
const int URLSIZE = 255;
const int PAHTSIZE = 512;
const int ENVSIZE = 255;
const char SERVERINFO[] = "Server: jdbhttpd/0.1.0\\r\\n";

#endif //MYTINYHTTPD_SERVERPARAMETER_H
