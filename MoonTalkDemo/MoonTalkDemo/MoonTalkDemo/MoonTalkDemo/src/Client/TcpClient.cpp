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
	unsigned long ul = 1; // ����Ϊ������ģʽ
	int ret = ioctlsocket(m_sockfd, FIONBIO, (unsigned long *)&ul);    //���óɷ�����ģʽ
	if (ret == SOCKET_ERROR)   //����ʧ��
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
	if (-1 == ::connect(m_sockfd, (sockaddr*)&m_sockaddr, sizeof(m_sockaddr)))	//������socket�����̷��أ���ʱ�������ֻ�δ���
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
				LoginFrame::GetInstance()->SetTipsText(_T("δ���ӵ�������"));
			}
		}
		else
		{
			LoginFrame::GetInstance()->SetTipsText(_T("δ���ӵ�������"));
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
		//�������ر�
		m_stateConnect = false;
	}
	else if(count == SOCKET_ERROR)
	{
		int err = WSAGetLastError();
		if (err == WSAEWOULDBLOCK)	//���Windows socket api�����ڷ���ʱ��ȴû����ɹ��ܣ���������WSAEWOULDBLOCK������롣
		{
			return;
		}
		else if (err == WSAETIMEDOUT)//��ʱ
		{
		}
		else if (err == WSAENETDOWN)//���ӶϿ�
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