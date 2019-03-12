#ifndef _MOONTALK_NET_SOCKET_H_
#define _MOONTALK_NET_SOCKET_H_

#include <unistd.h>
#include <arpa/inet.h>


class Socket
{
public:
	Socket(const char* ip, const int port);
	Socket(int sockfd, struct sockaddr_in addr);
	~Socket();
	int 			   fd() const{ return m_sockfd;}
	struct sockaddr_in addr() const {return m_addr;};
	void 		       bind();
	void 		       listen();
	void 			   setNonblocking();
	int 			   accept(sockaddr_in& addr);
	size_t             read(char* buf, size_t size);
	size_t			   write(char* buf, size_t size);
private:
	int 				m_sockfd;
	struct sockaddr_in 	m_addr;
};

#endif