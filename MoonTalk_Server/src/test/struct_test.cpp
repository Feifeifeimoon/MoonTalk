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
    connect(fd, (sockaddr*)&addr, sizeof(addr));

    std::cout << "connect success\n";
	int c;
	while (1)
	{
		/*std::cin >> c;
		send(fd, "123456", 6, 0);
		std::cin >> c;
		DataHeader dh;
		dh.type = MSG_TYPE_LOGIN;
		dh.length = 10;
		send(fd, (char*)&dh, sizeof(DataHeader), 0);*/
		std::cin >> c;
		LogIn login;
		login.type = MSG_TYPE_LOGIN;
		login.length = 10;
		strcpy(login.buf, "123456789");
		send(fd, (char*)&login, sizeof(LogIn), 0);
	}

}