#include <iostream>

#include "serv_80.h"

int main(int argc, char *argv[]){
/*    if (argc != 2) {
        std::cout << "Usage: tcp_th_srv <port>" << std::endl;
        return 1;
    }
*/
    server_6669 server6669(6669); // (atoi(argv[1]));
    if (!server6669.run())
        std::cout << "pthread_create() error" << std::endl;

    return 0;
}
