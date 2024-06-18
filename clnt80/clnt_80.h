#include <string>
#include <netinet/in.h>

class clnt_6669 {
    std::string clntName;
    char clnt_msg[5132]= {0};
    int connect_duration;
    int locl_port;
    int locl_sockl;
    struct sockaddr_in locl_addr;
public:
    clnt_6669(std::string clnt_name, int srv_port, int duration_seconds);
    ~clnt_6669();
    bool connect_to_server();
};

