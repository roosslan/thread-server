#include "clnt_80.h"

#include <cstring>
#include <iostream>
#include <thread>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


clnt_6669::clnt_6669(std::string clnt_name, int srv_port, int duration_seconds)
{
    clntName = clnt_name;
    connect_duration = duration_seconds;
    locl_port = srv_port;
    locl_sockl = socket(AF_INET, SOCK_STREAM, 0);
    locl_addr = {AF_INET, htons(locl_port), inet_addr("127.1")};
}

bool clnt_6669::connect_to_server() {
    if (connect(locl_sockl, (sockaddr *)&locl_addr, sizeof(locl_addr)) >= 0) {
    }
    else return false;

    for (int i = 1; i < connect_duration; ++i) {
        std::cout <<  clntName.c_str() << std::endl;
        send(locl_sockl, clntName.c_str(), sizeof(clntName.c_str()), 0);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep_1000 on Windows
    }
    return 0;
};

clnt_6669::~clnt_6669() {
    close(locl_sockl);
}