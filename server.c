#include "./tcp_socket/tcp_socket.h"
//相对于当前源文件被包含的头文件在哪里
#include <stdio.h>
int main(void) {

	//初始化socket网络库
	init_socket();
	SOCKET serfd = creatServerSocket();
	printf("等待客户端连接.....\n");
	//如果有客户端请求链接则则接受请求
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd)
	{
		err_print("accept");
		return 1;
	}
	printf("客户端连接OK.即将开始通讯\n");
	char revbuff[BUFSIZ] = { 0 }; //#define BUFSIZ  512/* Buffered I/O macros */
	char sendbuff[BUFSIZ] = { 0 };
	while (1)
	{
		printf("服务器接受数据:");
		//等待客户端回数据
		if (0 < recv(clifd, revbuff, BUFSIZ, 0))
		{
			printf("%s\n", revbuff);
		}
		//printf("服务器 send 接受的数据 %s\n", revbuff);
		//memcpy(sendbuff,revbuff,sizeof(revbuff));
		printf("服务器发送数据:");
		gets_s(sendbuff, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, sendbuff, strlen(sendbuff), 0))
		{
			err_print("send\n");
		}
		memset(revbuff,0,sizeof(revbuff));
		memset(sendbuff, 0, sizeof(sendbuff));
	}
	closesocket(clifd);//关闭客户端套接字
	closesocket(serfd);//关闭服务器套接字

	close_socket();//关闭网络库
	return 0;
}