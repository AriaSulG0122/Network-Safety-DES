#include <windows.h>
#include <stdio.h>
#include "MyServer.h"
#pragma comment(lib,"ws2_32.lib")

int runServer()
{
	//1.�����׽��ֿ�
	WORD wVersionRequested=MAKEWORD(2,2);
	WSADATA wsaData;
	int err = WSAStartup(wVersionRequested, &wsaData);
	if (err) { printf("S: Failed to load socket library\n"); }
	else {printf("S: Success to load socket library\n");}
	//2.����һ���׽��ֹ�ʹ��
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	//3.���׽��ְ󶨵����ص�ַ�Ͷ˿���
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6020);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	bind(ServerSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR));
	//4.���׽�������Ϊ����ģʽ���Խ��տͻ�������
	err = listen(ServerSocket, 5);
	if (err) { printf("S: Failed to listen\n"); }
	else { printf("S: Success to listen\n"); }
	//5.�ȴ������տͻ������󣬷����µ������׽���
	SOCKADDR_IN addr_out;
	int len = sizeof(SOCKADDR);
	SOCKET accSock = accept(ServerSocket, (SOCKADDR*)&addr_out, &len);
	//6.���÷��ص��׽��ֺͿͻ���ͨ��
	char s[256] = { 0 };
	recv(accSock, s, 256, 0);
	printf("S: Client Dada:%s \n", s);
	getchar();
	//7.�ر��׽���
	closesocket(ServerSocket);
	WSACleanup();
	return 0;
}