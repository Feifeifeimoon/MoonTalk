#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>


enum MSG_TYPE {
	MSG_TYPE_LOGIN = 1,
	MSG_TYPE_RET
};

struct DataHeader
{
	MSG_TYPE type;
	int length;
};

struct LogIn : public DataHeader
{
	char buf[64];
};

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8000);
	inet_aton("192.168.31.128", &addr.sin_addr);
    bind(fd, (sockaddr*)&addr, sizeof(addr));
    listen(fd, 50);
	while (1)
	{
        int cli_sockfd;
	    struct sockaddr_in cli_addr;
	    socklen_t len = sizeof(cli_addr);
	    cli_sockfd = accept(fd, (struct sockaddr *)&cli_addr, &len);
	    printf("%s connect at port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

	    /*int flag = fcntl(cli_sockfd, F_GETFL);          /* 修改connfd为非阻塞读 */
        //flag |= O_NONBLOCK;
        //fcntl(cli_sockfd, F_SETFL, flag);
        DataHeader dh = {};
        LogIn login = {};
        /*int count = recv(cli_sockfd, (char*)&login, sizeof(login), 0);
        printf("count = %d length = %d|%s\n", count, login.length, login.buf);*/

        char buf[128] = {};
        int count = recv(cli_sockfd, buf, sizeof(buf), 0);
        memcpy(&dh, buf, sizeof(dh));
        memcpy(&login, buf, sizeof(login));
        printf("count = %d length = %d|%s\n", count, strlen(buf),buf);
        printf("length = %d", dh.length);
        printf("count = %d length = %d|%s\n", count, login.length, login.buf);
	}

}