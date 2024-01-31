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

    int comm_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    // which will make the socket listen to all interfaces available on the machine
    sockaddr_in server_address{
        .sin_family = AF_INET,
        .sin_port = htons(10000),
    };

    // chained designators {.a.b=value} inside structs is not allowed in c++
    server_address.sin_addr.s_addr = htonl(0x7F000001);

    // type casting using pointers (bind is a generic function that works with both sockaddr_in and sockaddr_in6)
    // both ipv4 and ipv6 sockets have a family property which will be used when type casting
    int connect_successful = connect(comm_socket_fd, (sockaddr *)&server_address, sizeof(server_address));
    if (connect_successful < 0)
    {
        cout << "Failed to establish connection!" << endl;
        closesocket(comm_socket_fd);
        WSACleanup();
        return 0;
    }

    // sendinf
    const char *message = "{type:\"notification\", message:\"HelloWorld!\"}";
    send(comm_socket_fd, message, sizeof(message), 0);

    closesocket(comm_socket_fd);

    WSACleanup();

    return 0;
}