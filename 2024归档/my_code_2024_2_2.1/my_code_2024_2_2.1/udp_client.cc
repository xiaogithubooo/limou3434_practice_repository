//udp_client.cc
#include <iostream>
#include <string>

#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

const int readBuffSize = 1024;

static void Usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << "serverIp serverPort\n" << std::endl;
}

int main(int argc, char* argv[]) //./udp_client 127.0.0.1 8080
{
    //1.检查命令行输入
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(50);
    }

    //2.创建套接字
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        std::cerr << "socket error" << std::endl;
        exit(60);
    }

    //3.绑定套接字
    //但是一般不需要程序员自己 bind，这是因为客户端是被客户端使用的，如果程序员自己 bind 了，那么该客户端的一定是绑定了某个固定的 ip 和 port
    //万一在多个不关联的客户端同时启动的情况下，就会出现 port 绑定失败的情况，进而导致客户端启动失败）
    //将 bind 操作交给操作系统来做，操作系统对于哪些 port 没有被占用的情况最清楚了

    //4.向服务端发送数据
    std::string message;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    char readBuff[readBuffSize] = { 0 };
    while (true)
    {
        std::cout << "向服务器发送信号" << std::endl;
        std::getline(std::cin, message);
        if (message.c_str() == "exit")
            break;

        sendto(sock, message.c_str(), message.size(), 0,
            (struct sockaddr*)&server, sizeof(server));
        //第一次向服务器发送数据时，操作系统会在 sendto() 执行过程程中自动为服务端绑定

        //5.读取服务端返回的数据
        struct sockaddr_in temp; //占位符
        socklen_t len = sizeof(temp);
        ssize_t s = recvfrom(sock, readBuff, sizeof(readBuff), 0,
            (struct sockaddr*)&temp, &len);
        if (s > 0)
        {
            std::cout << "server echo# " << readBuff << std::endl;
        }
        else
        {
            std::cerr << "read error" << std::endl;
            exit(70);
        }
    }

    close(sock);
    std::cout << "bye~" << std::endl;

    return 0;
}