#include <iostream>
#include <winsock.h>

using namespace std;

void pretty_print_ip(u_long hex)
{
    u_long word = 0x000000FF;
    for(int i = 0; i < 4; i++)
    {
        cout << (hex & word) << ".";
        hex = hex >> 8;
    }
    cout << "\n";
}

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

    sockaddr_in comm_sock_addr;
    int comm_sock_addr_len = sizeof(comm_sock_addr);
    if(getsockname(comm_socket_fd, (sockaddr*)&comm_sock_addr, &comm_sock_addr_len) < 0)
    {
        cout << "error occurred when trying to get client socket name\n";
    }else{
        cout << "current ip: ";
        pretty_print_ip((u_long)comm_sock_addr.sin_addr.s_addr);
        cout << "current port : " << comm_sock_addr.sin_port << "\n";
    }

    // send 
    int operation = 0;
    string arr[6] = {"hello","hey","bye","fight", "test1","test2"};
    while(true)
    {
        char *message = strcpy(message,("put "+ arr[operation % 6] + ";").c_str());


        if(operation % 5 == 0)
        {
            strcpy(message,("contains "+ arr[operation % 6] + ";").c_str());
            int bytes_sent = send(comm_socket_fd, message, strlen(message), 0);
            cout << "message sent length : " << bytes_sent << "bytes\n" ;

            char response[1024] = {0};
            int bytes_received = recv(comm_socket_fd, response, sizeof(response), 0);
            cout << response << "\n";

        }
        else {
            int bytes_sent = send(comm_socket_fd, message, strlen(message), 0);
            cout << "message sent length : " << bytes_sent << "bytes\n" ;

        }
        
        operation++;

    }

    closesocket(comm_socket_fd);

    WSACleanup();

    return 0;
}