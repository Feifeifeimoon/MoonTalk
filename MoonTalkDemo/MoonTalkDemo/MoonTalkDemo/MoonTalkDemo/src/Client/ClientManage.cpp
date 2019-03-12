#include "ClientManage.h"
#include <thread>
#include "TcpClient.h"

ClientManage* ClientManage::m_instance = nullptr;
TcpClient*    ClientManage::m_loginClient = nullptr;
TcpClient*     ClientManage::m_msgClient = nullptr;
void ClientManage::init()
{
	if (m_loginClient == nullptr)
	{
		m_loginClient = new TcpClient("192.168.8.129", 8000);
		m_loginClient->connect();
	}
	std::thread t([]()
	{
		while (-1 != m_loginClient->fd())
		{
			if (!m_loginClient->isConnected())
			{
				if (!m_loginClient->connect())
				{
					Sleep(1000);
					continue;
				}
			}
			fd_set fdread;
			FD_ZERO(&fdread);
			FD_SET(m_loginClient->fd(), &fdread);
			int ret = select(NULL, &fdread, NULL, NULL, NULL);
			if (ret <= 0)
			{
				continue;
			}
			if (FD_ISSET(m_loginClient->fd(), &fdread))
			{
				m_loginClient->handleRead();
			}
		}
	});
	t.detach();
}

ClientManage* ClientManage::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ClientManage();
	}
	return m_instance;
}

TcpClient* ClientManage::GetLoginClient()
{
	return m_loginClient;
}

TcpClient* ClientManage::GetMsgClient()
{
	return m_msgClient;
}


void ClientManage::MsgClientConnect()
{
	if (m_msgClient == nullptr)
	{
		m_msgClient = new TcpClient("192.168.8.129", 8800);
		m_msgClient->connect();
	}
	std::thread t([]{
		while (-1 != m_msgClient->fd())
		{
			fd_set fdread;
			FD_ZERO(&fdread);
			FD_SET(m_msgClient->fd(), &fdread);
			int ret = select(NULL, &fdread, NULL, NULL, NULL);
			if (ret <= 0)
			{
				continue;
			}
			if (FD_ISSET(m_msgClient->fd(), &fdread))
			{
				m_msgClient->handleRead();
			}
		}
	});
	t.detach();

}

/*void ClientManage::_recv()
{
	while (1)
	{
		fd_set fdread;
		FD_ZERO(&fdread);
		if (-1 != m_loginClient->fd())
		{
			FD_SET(m_loginClient->fd(), &fdread);
		}
		int ret = select(NULL, &fdread, NULL, NULL, NULL);
		if (ret <= 0)
		{
			continue;
		}
		if (FD_ISSET(m_loginClient->fd(), &fdread))
		{
			m_loginClient->handleRead();
		}
	}
}*/



