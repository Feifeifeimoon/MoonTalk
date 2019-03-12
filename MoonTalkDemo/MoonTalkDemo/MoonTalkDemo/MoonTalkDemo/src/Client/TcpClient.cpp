#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "TcpClient.h"
//#include "../Login/LoginFrame.h"


TcpClient::TcpClient(const char* IP, const int port)
  :  m_IP(IP),
	 m_port(port),
	 m_sockfd(INVALID_SOCKET),
	 m_sockaddr({}),
	 m_stateConnect(false)
{
	_initSocket(IP, port);
}



void TcpClient::_initSocket(const char* IP, const int port)
{
	m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == m_sockfd)
	{
		exit(-1);
	}
	unsigned long ul = 1; // 设置为非阻塞模式
	int ret = ioctlsocket(m_sockfd, FIONBIO, (unsigned long *)&ul);    //设置成非阻塞模式
	if (ret == SOCKET_ERROR)   //设置失败
	{
		exit(-1);
	}


	m_sockaddr.sin_family = AF_INET;
	m_sockaddr.sin_addr.S_un.S_addr = inet_addr(IP);
	m_sockaddr.sin_port = htons(port);
}

bool TcpClient::connect()
{
	int error = -1;
	timeval tm;
	fd_set set;
	if (m_sockfd != -1)
	{
		::closesocket(m_sockfd);
		_initSocket(m_IP, m_port);
	}
	if (-1 == ::connect(m_sockfd, (sockaddr*)&m_sockaddr, sizeof(m_sockaddr)))	//非阻塞socket会立刻返回，此时三次握手还未完成
	{
		tm.tv_sec = 3;
		tm.tv_usec = 0;
		FD_ZERO(&set);
		FD_SET(m_sockfd, &set);
		if (select(m_sockfd + 1, NULL, &set, NULL, &tm) > 0)
		{
			if (!FD_ISSET(m_sockfd, &set))
			{
				return false;
				LoginFrame::GetInstance()->SetTipsText(_T("未连接到服务器"));
			}
		}
		else
		{
			LoginFrame::GetInstance()->SetTipsText(_T("未连接到服务器"));
			return false;
		}
	}
	LoginFrame::GetInstance()->SetTipsText(_T(""));
	m_stateConnect = true;
	return true;
}

int TcpClient::send(char* buf, size_t size)
{
	if (!m_stateConnect)
		return -1;
	return ::send(m_sockfd, buf, size, 0);
}

int TcpClient::recv(char* buf, size_t size)
{
	return ::recv(m_sockfd, buf, size, 0);
}

void TcpClient::handleRead()
{
	char buf[1024] = {};
	int count = ::recv(m_sockfd, buf, sizeof(buf), 0);
	if (count > 0)
	{
		if (m_messageCallback != nullptr)
			m_messageCallback(buf);
	}
	else if (count == 0)
	{
		//服务器关闭
		m_stateConnect = false;
	}
	else if(count == SOCKET_ERROR)
	{
		int err = WSAGetLastError();
		if (err == WSAEWOULDBLOCK)	//如果Windows socket api函数在返回时，却没有完成功能，它将返回WSAEWOULDBLOCK错误代码。
		{
			return;
		}
		else if (err == WSAETIMEDOUT)//超时
		{
		}
		else if (err == WSAENETDOWN)//连接断开
		{
		}
		m_stateConnect = false;
	}
}

TcpClient::~TcpClient()
{
	closesocket(m_sockfd);
	WSACleanup();
}