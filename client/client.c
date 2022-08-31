#include "../tcp_socket/tcp_socket.h"
//相对于当前源文件被包含的头文件在哪里
#include <stdio.h>
#include <string.h>
int main(void) {

	//初始化socket网络库
	init_socket();


	SOCKET clifd =  creatClientSocket("192.168.76.1");//电脑主机iP
	char revbuff[BUFSIZ] = { 0 }; //#define BUFSIZ  512/* Buffered I/O macros */
	char sendbuff[BUFSIZ] = { 0 };
	while (1)
	{
		printf("客户端发送数据:");
		gets_s(sendbuff, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, sendbuff, strlen(sendbuff), 0))
		{
			err_print("send\n");
		}
	
		//等待服务器回数据
		if (0 < recv(clifd, revbuff, BUFSIZ, 0))
		{
			printf("客户端 rev data = %s\n", revbuff);
		}
		memset(revbuff, 0, sizeof(revbuff));
		memset(sendbuff, 0, sizeof(sendbuff));
	}
	closesocket(clifd);//关闭客户端套接字
	close_socket();//关闭网络库
	getch();
	return 0;
}