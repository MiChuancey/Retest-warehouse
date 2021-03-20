//
// Created by Administrator on 2021/3/18.
//
#include "init.h"


static void showUsage() {

}

static void initLoginConfig() {

}

static void initDevice(){

}

static void initArgument(const int* argc,char*** argv) {
//    extern u_int background_running;
//    extern u_int exitFlag;
    static struct option longOptions[] = {
            {"help",            no_argument,       0,                   'h'},
            {"background",      no_argument,       &background_running, 1},
            {"username",        required_argument, 0,                   'u'},
            {"password",        required_argument, 0,                   'p'},
            {"ip",              required_argument, 0,                   4},
            {"mask",            required_argument, 0,                   5},
            {"gateway",         required_argument, 0,                   'g'},
            {"dns",             required_argument, 0,                   'd'},
            {"service_company", required_argument, 0,                   's'},
            {"interface_card",  required_argument, 0,                   'i'},
            {0, 0,                                 0,                   0}
    };

    while (1) {
        int optIndex=0;
        int opt=getopt_long(*argc,*argv,"u:p:s:g:d:hbkni",longOptions,&optIndex);
        if (opt==-1) break;

        switch (opt) {
            case 0:
                break;
            case 'b':
                background_running = 1;
                break;
            case 4:
                user_input_ipaddr = optarg;
                break;
            case 5:
                user_input_mask = optarg;
                break;
            case 'u':
                username = optarg;
                break;
            case 'p':
                password = optarg;
                break;
            case 'g':
                user_input_gateway = optarg;
                break;
            case 'd':
                user_input_dns = optarg;
                break;
            case 's':
                service_company = optarg;
                break;
            case 'k':
                exitFlag=1;
                break;
            case 'i':
                network_interface_card_name = optarg;
                break;
            case 'h':
                showUsage();
                exit(EXIT_SUCCESS);
            case '?':
                if (optopt == 'u'||optopt=='p'||optopt=='s'||optopt=='g'||optopt=='d')
                    fprintf(stderr, "选项 -%c 需要加入参数.\n", optopt);
                exit(EXIT_FAILURE);
                break;
            default:
                fprintf(stderr, "未知的选项 '%c'.\n", opt);
                exit(EXIT_FAILURE);
        }
    }

}