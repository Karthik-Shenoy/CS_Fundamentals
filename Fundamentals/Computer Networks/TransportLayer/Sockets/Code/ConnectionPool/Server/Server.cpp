#include<iostream>
#include<winsock.h>
using namespace std;

const short PORT = 5000;

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "Failed to initialize Winsock." << endl;
        return 1;
    }
    sockaddr_in server_sock_addr {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
    };
    // address in the long format 127.0.0.1
    server_sock_addr.sin_addr.S_un.S_addr = htonl(0x70000001);

    // Create socket fd using factory function
    int listening_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    

    return 0;
}