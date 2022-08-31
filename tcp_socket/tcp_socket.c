#include "tcp_socket.h"

bool init_socket()
{
	WSADATA lpw_data;
	//��һ������socket�汾�ţ��ڶ����������
	if (0 != WSAStartup(MAKEWORD(2, 2), &lpw_data)) //WSA window socket sync  �첽�׽���  
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
		//1�����յ�socket
		//AF_INET ����Э��汾 ipv SOCK_STREAM �׽��������� ��TCP��Ӧ
		SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (fd == INVALID_SOCKET)//�����׽���ʧ��
		{
			err_print("creatServerSocket\n");
			return INVALID_SOCKET;
		}
		//2���׽���
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;//ipv4����
		addr.sin_port = htons(PORT);//�����ֽ���ת��Ϊ�����ֽ���
		addr.sin_addr.S_un.S_addr = ADDR_ANY;//������IP  inet_addr("192.168.2.3");//���ƶ�IP

		if (SOCKET_ERROR == bind(fd, &addr, sizeof(struct sockaddr_in)))
		{
			err_print("bind");
			return SOCKET_ERROR;
		}
		//3�����׽���
		listen(fd, 5);//����5���ͻ���
		return fd;
}

SOCKET creatClientSocket(const char * ip)
{
	//1�����յ�socket
		//AF_INET ����Э��汾 ipv SOCK_STREAM �׽��������� ��TCP��Ӧ
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)//�����׽���ʧ��
	{
		err_print("creatServerSocket");
		return INVALID_SOCKET;
	}
	//2���׽���
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//ipv4����
	addr.sin_port = htons(PORT);//�����ֽ���ת��Ϊ�����ֽ���
	addr.sin_addr.S_un.S_addr = inet_addr(ip);//��Ҫ���ӵķ�����IP��ַ
	if (INVALID_SOCKET == connect(fd,(struct sockaddr*)&addr, sizeof(addr)))
	{
		    err_print("creatClientSocket");
			return false;
	}
	return fd;
}