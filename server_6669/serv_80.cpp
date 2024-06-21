#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <memory>
#include <fstream>

#include "serv_80.h"

void * write_to_file(void* clnt_sock) {
    int sock_num = *((int*)clnt_sock);

    char clnt_msg[5132] = {0};
    while (true) {
        int bytes_read = recv(sock_num, clnt_msg, 5132, 0);
        if (0 == bytes_read) break; // std::cout << "Client disconnected" << std::endl;
        if (-1 == bytes_read) break; // std::cout << "recv() error" << std::endl;

        std::cout << pthread_self() << "/" << sock_num << std::endl;
        std::cout << clnt_msg << std::endl;
        // пишем в файл и чистим буфер

        std::ofstream logfile("/home/rasa/access.log", std::ios_base::app);
        logfile << clnt_msg << std::endl;
        logfile.close();

        memset(clnt_msg, 0, 5132);

    }
    return nullptr;
}

server_6669::server_6669(int srv_port) {
    locl_port = srv_port;
};

bool server_6669::run() {
    socklen_t clnt_len = sizeof(clnt_addr);

    locl_sockl = socket(AF_INET, SOCK_STREAM, 0);
    locl_addr = {AF_INET, htons(locl_port), inet_addr("127.1")}; // лучше параметром 0.0.0.0
    // вяжем пару аддр/сокет
    bind(locl_sockl,  (sockaddr *)&locl_addr, sizeof(locl_addr));
    listen(locl_sockl, 10000);
    std::cout << "Server listening on 127.0.0.1:" << locl_port << std::endl;
    // слушаем


    pthread_t thread_id;

    while (int clnt_sock = accept(locl_sockl,  (sockaddr *)&clnt_addr, &clnt_len)) {
        // конн.аксептд
/*        auto const thread6669 = std::make_shared<Thread6669>(clnt_sock);
// // //       std::shared_ptr<Thread6669> thread6669(new Thread6669(clnt_sock));
        thread6669->Start();
        std::cout << "New client connected" << std::endl;
//        thread6669->Wait();
 */
        const std::shared_ptr parameters = std::make_shared<int>(clnt_sock);
        if(pthread_create(&thread_id, nullptr, &write_to_file, parameters.get()) < 0)
        {
            // error
        };
    }
    return true;
}

server_6669::~server_6669() {
    close(locl_sockl);
};