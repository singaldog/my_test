#include "./tcp_socket/tcp_socket.h"
//����ڵ�ǰԴ�ļ���������ͷ�ļ�������
#include <stdio.h>
int main(void) {

	//��ʼ��socket�����
	init_socket();
	SOCKET serfd = creatServerSocket();
	printf("�ȴ��ͻ�������.....\n");
	//����пͻ����������������������
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd)
	{
		err_print("accept");
		return 1;
	}
	printf("�ͻ�������OK.������ʼͨѶ\n");
	char revbuff[BUFSIZ] = { 0 }; //#define BUFSIZ  512/* Buffered I/O macros */
	char sendbuff[BUFSIZ] = { 0 };
	while (1)
	{
		printf("��������������:");
		//�ȴ��ͻ��˻�����
		if (0 < recv(clifd, revbuff, BUFSIZ, 0))
		{
			printf("%s\n", revbuff);
		}
		//printf("������ send ���ܵ����� %s\n", revbuff);
		//memcpy(sendbuff,revbuff,sizeof(revbuff));
		printf("��������������:");
		gets_s(sendbuff, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, sendbuff, strlen(sendbuff), 0))
		{
			err_print("send\n");
		}
		memset(revbuff,0,sizeof(revbuff));
		memset(sendbuff, 0, sizeof(sendbuff));
	}
	closesocket(clifd);//�رտͻ����׽���
	closesocket(serfd);//�رշ������׽���

	close_socket();//�ر������
	return 0;
}