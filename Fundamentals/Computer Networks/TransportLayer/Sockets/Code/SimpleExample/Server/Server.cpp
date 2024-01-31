#include <iostream>
#include <winsock.h>

using namespace std;

int main()
{

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "Failed to initialize Winsock." << endl;
        return 1;
    }

    int listening_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    // we will specify IP address as INADDR_ANY (0.0.0.0)
    // which will make the socket listen to all interfaces available on the machine
    sockaddr_in server_address{
        .sin_family = AF_INET,
        .sin_port = htons(50000),
    };
    // chained designators {.a.b=value} inside structs is not allowed in c++
    server_address.sin_addr.s_addr = INADDR_ANY;

    // type casting using pointers (bind is a generic function that works with both sockaddr_in and sockaddr_in6)
    // both ipv4 and ipv6 sockets have a family property which will be used when type casting
    int bind_successful = bind(listening_socket_fd, (sockaddr *)&server_address, sizeof(server_address));

    if (bind_successful < 0)
    {
        cout << "error when binding the socket" << endl;
        closesocket(listening_socket_fd);
        WSACleanup();
        return 0;
    }

    // listen on the listening socket
    int listen_successful = listen(listening_socket_fd, 5);

    if (listen_successful < 0)
    {
        cout << "error when listening on the socket" << endl;
        closesocket(listening_socket_fd);
        WSACleanup();
        return 0;
    }

    cout << "listening on port : 5000" << endl;

    int comm_socket_fd = accept(listening_socket_fd, nullptr, nullptr);

    // receiving data
    char buffer[2048] = {0};
    recv(comm_socket_fd, buffer, sizeof(buffer), 0);

    cout << buffer << "\n";

    closesocket(listening_socket_fd);
    WSACleanup();

    return 0;
}