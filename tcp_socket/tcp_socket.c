#include "tcp_socket.h"

bool init_socket()
{
	WSADATA lpw_data;
	//第一个参数socket版本号，第二个输出参数
	if (0 != WSAStartup(MAKEWORD(2, 2), &lpw_data)) //WSA window socket sync  异步套接字  
	{
		err_print("init_socket\n");
		return false;
	}
	return true;
}

bool close_socket()
{
	if (0 != WSACleanup())
	{
		err_print("close_socket\n");
		return false;
	}
	return true;
}



SOCKET creatServerSocket()
{
		//1创建空的socket
		//AF_INET 网络协议版本 ipv SOCK_STREAM 套接字数据流 和TCP对应
		SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (fd == INVALID_SOCKET)//创建套接字失败
		{
			err_print("creatServerSocket\n");
			return INVALID_SOCKET;
		}
		//2绑定套接字
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;//ipv4家族
		addr.sin_port = htons(PORT);//本地字节序转换为网络字节序
		addr.sin_addr.S_un.S_addr = ADDR_ANY;//绑定任意IP  inet_addr("192.168.2.3");//绑定制定IP

		if (SOCKET_ERROR == bind(fd, &addr, sizeof(struct sockaddr_in)))
		{
			err_print("bind");
			return SOCKET_ERROR;
		}
		//3监听套接字
		listen(fd, 5);//监听5个客户端
		return fd;
}

SOCKET creatClientSocket(const char * ip)
{
	//1创建空的socket
		//AF_INET 网络协议版本 ipv SOCK_STREAM 套接字数据流 和TCP对应
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)//创建套接字失败
	{
		err_print("creatServerSocket");
		return INVALID_SOCKET;
	}
	//2绑定套接字
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//ipv4家族
	addr.sin_port = htons(PORT);//本地字节序转换为网络字节序
	addr.sin_addr.S_un.S_addr = inet_addr(ip);//绑定要连接的服务器IP地址
	if (INVALID_SOCKET == connect(fd,(struct sockaddr*)&addr, sizeof(addr)))
	{
		    err_print("creatClientSocket");
			return false;
	}
	return fd;
}