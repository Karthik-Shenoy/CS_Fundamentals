#include <iostream>
#include <thread>
#include <winsock.h>
#include <vector>
#include <set>

using namespace std;

vector<pair<string, string>> queries;

void get_data(char buffer[], int buff_size)
{
    string command, data;
    bool commandFound = false;
    for (int i = 0; i < buff_size; i++)
    {
        if (buffer[i] == ';')
        {
            queries.push_back({command, data});
            command = "";
            data = "";
            commandFound = false;
            continue;
        }
        if (buffer[i] == ' ')
        {
            commandFound = true;
            continue;
        }
        if (!commandFound)
        {
            command += buffer[i];
        }
        else
        {
            data += buffer[i];
        }
    }
}

void handle_socket(int comm_socket_fd)
{
    set<string> mem_cache;
    cout << "In new thread"
         << "\n";
    while (true)
    {
        char buffer[1024] = {0};
        int recv_flag = recv(comm_socket_fd, buffer, sizeof(buffer), 0);

        if (recv_flag < 0)
        {
            cout << "Some error occurred when reading from the socket\n";
            return;
        }
        else if (recv_flag == 0)
        {
            cout << "connection gracefully closed by the client\n";
            return;
        }

        get_data(buffer, recv_flag);
        for (pair<string, string> &query : queries)
        {
            cout << query.first << " " << query.second << "\n";
            if (query.first == "put")
            {
                mem_cache.insert(query.second);
            }
            else if (query.first == "contains")
            {
                char response[30];
                cout << "\ncontents : ";
                for (auto x : mem_cache)
                {
                    cout << x << ",";
                }
                cout << "\n";
                if (mem_cache.find(query.second) != mem_cache.end())
                {

                    strcpy(response, "found");
                }
                else
                {
                    strcpy(response, "not found");
                }
                send(comm_socket_fd, response, strlen(response), 0);
            }
        }
        queries.clear();
    }
}

//-lwsock32 -lws2_32
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
    sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = htons(10000),
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
    int listen_successful = listen(listening_socket_fd, 10);
    if (listen_successful < 0)
    {
        cout << "error when listening on the socket" << endl;
        closesocket(listening_socket_fd);
        WSACleanup();
        return 0;
    }
    cout << "listening on port : 5000" << endl;
    vector<thread> socket_handlers;

    while (true)
    {
        int comm_socket_fd = accept(listening_socket_fd, nullptr, nullptr);
        socket_handlers.push_back(thread(&handle_socket, comm_socket_fd));
    }

    for (thread &th : socket_handlers)
    {
        th.join();
    }

    closesocket(listening_socket_fd);
    WSACleanup();

    return 0;
}
