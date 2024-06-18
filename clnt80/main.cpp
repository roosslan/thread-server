#include <iostream>
#include <chrono>
#include "clnt_80.h"

int main(int argc, char *argv[]){
    if (argc != 4) {
        std::cout << "Usage: clnt_6669.elf <client's name > <server's port> <duration in seconds>" << std::endl;
        return  1;
    }
    std::cout << "Usage: clnt_6669.elf <client's name > <server's port> <duration in seconds>" << std::endl;
    clnt_6669 clnt80(std::string(argv[1]), atoi(argv[2]), atoi(argv[3]));
    
    if (!clnt80.connect_to_server()) std::cout << "Server is not running on port " << argv[2] << std::endl;

    return 0;
}