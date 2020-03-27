#include <windows.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

int runClient()
{
	//1.�����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	int err = WSAStartup(wVersionRequested, &wsaData);
	if (err) { printf("C: Failed to load socket library\n"); }
	else { printf("C: Success to load socket library\n"); }
	//2.����һ���׽��ֹ�ʹ��
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	//3.�������������������
	SOCKADDR_IN socksin;//��¼�������˵�ַ
	socksin.sin_family = AF_INET;
	socksin.sin_port = htons(6020);
	socksin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int rf = connect(ServerSocket, (SOCKADDR*)&socksin, sizeof(socksin));
	if (rf == SOCKET_ERROR)
	{
		printf("C: Failed to connect to server\n");
	}
	else
	{
		printf("C: Success to connect to server\nC: Please input the plaintext:");
		char plaintext[100];
		scanf("%s", plaintext);
		send(ServerSocket, plaintext, strlen(plaintext), 0);
	}
	getchar();
	closesocket(ServerSocket);
	WSACleanup();
	return 0;
}