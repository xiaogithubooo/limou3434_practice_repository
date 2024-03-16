//udp_client.cc(Windows 也适用的版本)
#pragma warning(disable:4996)
#include <WinSock2.h>
#include <iostream>
#include <string>

#pragma comment(lib,"ws2_32.lib") //这一句基本是 Windows 下套接字编程的固定用法，Windows 独有的

uint16_t serverport = 8080;
std::string serverip = "111.230.60.61";

int main()
{
	WSADATA WSAData;
	WORD sockVersion = MAKEWORD(2, 2); //设置库版本，Windows 独有的
	if (WSAStartup(sockVersion, &WSAData) != 0) //根据版本加载对应的库，Windows 独有的
		return 0;

	//初始套接字
	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == clientSocket)
	{
		std::cout << "socket error!";
		return 0;
	}

	//设置套接字
	sockaddr_in dstAddr;
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_port = htons(serverport);
	dstAddr.sin_addr.S_un.S_addr = inet_addr(serverip.c_str());

	while (true)
	{
		//向服务端发送
		std::string message;
		std::cout << "client >: ";
		std::getline(std::cin, message);
		if (message == "exit")
			break;
		if (sendto(clientSocket, message.c_str(), (int)message.size(), 0, (sockaddr*)&dstAddr, (int)sizeof(dstAddr)) >= 0)
		{
			//...
		}
		else
		{
			std::cout << "sendto() error!";
			exit(10);
		}

		//从服务端读取
		char buffer[1024] = { 0 };
		struct sockaddr_in temp;
		int len = sizeof(temp);
		if (recvfrom(clientSocket, buffer, sizeof buffer, 0, (sockaddr*)&temp, &len) >= 0)
		{
			std::cout << "server echo >: " << buffer << std::endl;
		}
		else
		{
			std::cout << "recvfrom() error!";
			exit(20);
		}
	}

	closesocket(clientSocket); //关闭文件描述符，windows 独有的
	WSACleanup(); //库的清理，windows 独有的

	return 0;
}