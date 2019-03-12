#include "TcpServer.h"
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "EventLoop.h"
#include "EventLoopThread.h"
#include "EventLoopThreadPool.h"


TcpServer::TcpServer(const char *ip, int port)
  : m_eventloop(new EventLoop()), 
  	m_acceptor_listn(m_eventloop, ip, port),
	m_threadPool(new EventLoopThreadPool(5)),
	m_connIndex(1)
{
	m_acceptor_listn.setNewConnectionCallBack(
		std::bind(&TcpServer::newConnection, this, std::placeholders::_1, std::placeholders::_2));
}

void TcpServer::newConnection(int sockfd, struct sockaddr_in addr)
{
	struct sockaddr_in cli_addr = addr;
	EventLoop* loop = m_threadPool->getNextLoop();
	TcpConnectionPtr conn (new TcpConnection(loop, sockfd, addr, m_connIndex));
	if(m_messageCallback)
	{
		conn->setMessageCallback(m_messageCallback);
	}
	else
	{
		conn->setMessageCallback(
		std::bind(&TcpServer::newMessage, this, std::placeholders::_1, std::placeholders::_2));
	}
	conn->setCloseCallback(
		std::bind(&TcpServer::onClose, this, std::placeholders::_1));
	conn->enableReading();
	m_tcpConnList[m_connIndex] = conn;
	++m_connIndex;
	printf("new connection jion , now have %d conns\n", (int)m_tcpConnList.size());
}


void TcpServer::newMessage(TcpConnection& conn, char* buf)
{
	printf("recv|%s|from %s:%d\n", buf, inet_ntoa(conn.addr().sin_addr), ntohs(conn.addr().sin_port));
}


void TcpServer::onClose(TcpConnection& conn)
{
	m_tcpConnList.erase(conn.index());
	printf("one connection close , now have %d conns\n", (int)m_tcpConnList.size());

}

void TcpServer::run()
{
	m_threadPool->start();
	m_acceptor_listn.listen();
}
