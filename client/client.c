#include "../tcp_socket/tcp_socket.h"
//����ڵ�ǰԴ�ļ���������ͷ�ļ�������
#include <stdio.h>
#include <string.h>
int main(void) {

	//��ʼ��socket�����
	init_socket();


	SOCKET clifd =  creatClientSocket("192.168.76.1");//��������iP
	char revbuff[BUFSIZ] = { 0 }; //#define BUFSIZ  512/* Buffered I/O macros */
	char sendbuff[BUFSIZ] = { 0 };
	while (1)
	{
		printf("�ͻ��˷�������:");
		gets_s(sendbuff, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, sendbuff, strlen(sendbuff), 0))
		{
			err_print("send\n");
		}
	
		//�ȴ�������������
		if (0 < recv(clifd, revbuff, BUFSIZ, 0))
		{
			printf("�ͻ��� rev data = %s\n", revbuff);
		}
		memset(revbuff, 0, sizeof(revbuff));
		memset(sendbuff, 0, sizeof(sendbuff));
	}
	closesocket(clifd);//�رտͻ����׽���
	close_socket();//�ر������
	getch();
	return 0;
}