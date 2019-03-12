#include "Socket.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>

Socket::Socket(const char* ip, const int port)
{
	m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if( -1 == m_sockfd )
	{
		std::cout << "socket failed\n";
		exit(-1);
	}
	bzero(&m_addr, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
	m_addr.sin_port = htons(port);
	inet_aton(ip, &m_addr.sin_addr);
}


Socket::Socket(int sockfd, struct sockaddr_in m_addr)
	: m_sockfd(sockfd),
	  m_addr(m_addr)
{

}

void Socket::bind()
{
	int on = 1;
	if((setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) == -1)
	{
		perror("setsockopt failed");
	}
	if(-1 ==  ::bind(m_sockfd, (struct sockaddr* )&m_addr, sizeof(m_addr)))
	{
		perror("bind failed");
		return ;
	}
	return ;
}

void Socket::listen()
{
	if( -1 == ::listen(m_sockfd, 20))
	{
		std::cout << "listen failed\n";
		return ;
	}
	return ;
}


void Socket::setNonblocking()
{
	int flag = fcntl(m_sockfd, F_GETFL);          /* 修改connfd为非阻塞读 */
    flag |= O_NONBLOCK;
    fcntl(m_sockfd, F_SETFL, flag);
}

int Socket::accept(sockaddr_in& conn_addr)
{
	int conn_sockfd;
	socklen_t len = sizeof(conn_addr);
	bzero(&conn_addr, sizeof(conn_addr));
	conn_sockfd = ::accept(m_sockfd, (sockaddr*)&conn_addr, &len);
	if(conn_sockfd < 0)
	{
		perror("accept failed");
	}
	return conn_sockfd;
}


size_t Socket::read(char* buf, size_t size)
{
	return ::read(m_sockfd, buf, size);
}

size_t Socket::write(char* buf, size_t size)
{
	return ::write(m_sockfd, buf, size);
}


Socket::~Socket()
{
	close(m_sockfd);
}


