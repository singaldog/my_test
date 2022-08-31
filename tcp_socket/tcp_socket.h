#ifndef _TCP_SOCKET_H
#define _TCP_SOCKET_H


#include <stdio.h>
#include "stdbool.h"//布尔头文件
#include <WinSock2.h>//windows平台的网络库头文件
#pragma comment(lib,"ws2_32.lib") //包含网络库


#define err_print(message)   printf("错误信息在%d行 %s错误代码为%d",__LINE__,message,WSAGetLastError())


#define PORT 8888

//打开网络库
bool init_socket();
//关闭网络库
bool close_socket();
//创建服务器socket
SOCKET creatServerSocket();
//创建客户端socket
SOCKET creatClientSocket(const char* ip);

#endif
