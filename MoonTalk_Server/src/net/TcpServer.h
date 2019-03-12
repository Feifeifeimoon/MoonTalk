#ifndef _MOONTALK_NET_TCPSERVER_H_
#define _MOONTALK_NET_TCPSERVER_H_

#define MAX_CONNECT 20

#include <unistd.h>
#include <arpa/inet.h>
#include <mutex>  			//std::mutex
#include <map>				//std::map
#include <memory>			//std::shared_ptr
#include <atomic>			//std::stomic_int
#include "Acceptor.h"
#include "TcpConnection.h"
class EventLoop;
class EventLoopThreadPool;
class TcpServer 
{

public:
	typedef std::function<void(TcpConnection& conn, char* buf)> MessageCallback;
	typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
	TcpServer(const char *ip, int port);
	~TcpServer();
	void run();
	void setMessageCallback(const MessageCallback& cb) { m_messageCallback = cb; }
private:
	void newConnection(int sockfd, struct sockaddr_in addr);
	void newMessage(TcpConnection&, char* buf);
	void onClose(TcpConnection&);
private:
	EventLoop* 					    m_eventloop; 
	Acceptor 				        m_acceptor_listn;
	EventLoopThreadPool*		    m_threadPool;	 
	std::map<int ,TcpConnectionPtr> m_tcpConnList;
	std::atomic_int 			    m_connIndex;
	MessageCallback 			    m_messageCallback;
	std::mutex  				    m_mutex;
};


#endif
