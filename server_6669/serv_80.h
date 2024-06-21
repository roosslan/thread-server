

#ifndef SERV_80_H
#define SERV_80_H

#include <string>
#include <netinet/in.h>



class server_6669 {
    struct sockaddr_in clnt_addr, locl_addr;

    int locl_port;
    int locl_sockl;

public:
    server_6669(int srv_port);
    ~server_6669();
    bool run();
};



#endif //SERV_80_H
