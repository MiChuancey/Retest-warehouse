#include <stdio.h>
#include <stdlib.h>
#include "init.h"

int main(int argc,char** argv) {
    if (argc < 2) {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    initArgument(&argc,&argv);


    return 0;
}
