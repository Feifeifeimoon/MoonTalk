#include <iostream>

#include "./src/net/TcpServer.h"
#include "./src/protobuf/login.pb.h"

void newMessage(TcpConnection& conn, char* buf)
{
	User user;
	//printf("recv|%s|from %s:%d\n", buf, inet_ntoa(conn.addr().sin_addr), ntohs(conn.addr().sin_port));
	user.ParseFromArray(buf, strlen(buf));
	std::cout << user.account() << "|" << user.password() <<  "|" << inet_ntoa(conn.addr().sin_addr) << std::endl;
	
}

int main(void)
{
	TcpServer* tcpServer = new TcpServer("192.168.31.128", 8000);
	tcpServer->setMessageCallback(newMessage);
	tcpServer->run();
	while(1);
}