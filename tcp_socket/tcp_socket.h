#ifndef _TCP_SOCKET_H
#define _TCP_SOCKET_H


#include <stdio.h>
#include "stdbool.h"//����ͷ�ļ�
#include <WinSock2.h>//windowsƽ̨�������ͷ�ļ�
#pragma comment(lib,"ws2_32.lib") //���������


#define err_print(message)   printf("������Ϣ��%d�� %s�������Ϊ%d",__LINE__,message,WSAGetLastError())


#define PORT 8888

//�������
bool init_socket();
//�ر������
bool close_socket();
//����������socket
SOCKET creatServerSocket();
//�����ͻ���socket
SOCKET creatClientSocket(const char* ip);

#endif
