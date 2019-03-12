#ifndef _SRC_CLIENT__CLIENT_H
#define _SRC_CLIENT__CLIENT_H

#include "../Login/LoginFrame.h"
#include <WinSock2.h>
#include <functional>

class TcpClient
{
	typedef std::function<void(char* buf)> MessageCallback;
public:
	TcpClient(const char* IP, const int port);
	~TcpClient();
	SOCKET fd() const { return m_sockfd;  }
	bool connect();
	int send(char* buf, size_t size);
	int recv(char* buf, size_t size);
	void close() { ::closesocket(m_sockfd); m_sockfd = -1; }
	void setMessageCallback(const MessageCallback& cb) { m_messageCallback = cb;  }
	void handleRead();
	bool isConnected() { return m_stateConnect; }
	void _initSocket(const char* IP, const int port);  
private:
	const char*     m_IP;
	const int       m_port;
	SOCKET          m_sockfd = -1;
	sockaddr_in     m_sockaddr;
	MessageCallback m_messageCallback = nullptr;
	bool            m_stateConnect;
};

#endif


