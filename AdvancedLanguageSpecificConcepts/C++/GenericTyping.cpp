// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct generic_socket
{
    u_short type;
    // 16+32 = 48, 64+16 = 80
    u_short IPAddr[10];
};

// union IPv4
// {
//     struct W_IPv4
//     {
//         short word1;
//         short word2;
//     };
//     struct L_IPv4
//     {
//         long ip_addr;
//     };
// };

// union IPv6
// {
//     struct W_IPv6
//     {
//         short word1;
//         short word2;
//         short word3;
//         short word4;
//     };
//     struct LL_IPv6
//     {
//         long long ip_addr;
//     };
// };

struct SocketAddressV4
{
    short type;
    u_short port;
    long long IPAddr;
};

struct SocketAddressV6
{
    short type;
    u_short port;
    long IPAddr;
};

int main()
{
    SocketAddressV4 sv4 = {
        1,
        0xFFFF,
        0xFFFFFFFF
    };

    generic_socket* gs = (generic_socket*)&sv4;
    cout << gs->type << "\n";
    for(int i = 0; i < 4; i++)
    {
        cout << gs->IPAddr[i] << endl; 
    }

    return 0;
}