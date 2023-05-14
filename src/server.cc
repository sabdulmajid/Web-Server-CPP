#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10

int main() {
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }
    
    // Bind the socket to an address and port
    sockaddr_in address;
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) == -1) {
        std::cerr << "Failed to bind socket to address" << std::endl;
        return 1;
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) == -1) {
        std::cerr << "Failed to listen for connections" << std::endl;
        return 1;
    }
    
    // Create a queue to store the connections
    std::queue<int> connections;
    
   