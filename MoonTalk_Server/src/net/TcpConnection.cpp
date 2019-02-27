#include "TcpConnection.h"

#include "string.h"
#include "Channel.h"
#include "EventLoop.h"

TcpConnection::TcpConnection(EventLoop* eventloop,int sockfd, struct sockaddr_in addr, const int index)
    : m_eventloop(eventloop),
      m_socket_conn(sockfd, addr),
      m_channel(new Channel(eventloop, sockfd)),
      m_index(index)
{
    m_channel->setReadCallBack(
        std::bind(&TcpConnection::handleRead, this));
    m_socket_conn.setNonblocking();
}

TcpConnection::~TcpConnection()
{
    printf("~TcpConnection() \n");
}



void TcpConnection::enableReading()
{
    m_channel->enableReading();
}
void TcpConnection::disableReading()
{
    m_channel->disableReading();
}
void TcpConnection::enableWriting()
{
    m_channel->enableWriting();
}
void TcpConnection::disableWriting()
{
    m_channel->disableWriting();
}
void TcpConnection::disableAll()
{
    m_channel->disableAll();
}

void TcpConnection::handleRead()
{
    char buf[128] = {0};
    size_t count = m_socket_conn.read(buf, sizeof(buf));
    if(count > 0)
    {
        if(m_messageCallback)
            m_messageCallback(*this, buf);
    }
    else if (count == 0)
    {
        handleClose();
        if(m_closeCallback)
            m_closeCallback(*this);
    }
    else
    {
        perror("read failed");
    }
    
}

void TcpConnection::handleClose()
{
    m_channel->disableAll();
}


void TcpConnection::send(char* buf, size_t size)
{
    m_socket_conn.write(buf, size);
}
