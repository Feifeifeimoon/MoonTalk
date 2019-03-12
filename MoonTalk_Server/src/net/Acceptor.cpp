#include "Acceptor.h"
#include "Channel.h"
#include "EventLoop.h"


Acceptor::Acceptor(EventLoop* eventloop,const char* ip, const int port)
    : m_eventloop(eventloop), 
      m_socket_listen(ip, port),
      m_channel(new Channel(m_eventloop, m_socket_listen.fd()))
{
    m_channel->setReadCallBack(
        std::bind(&Acceptor::handleRead, this));
    m_socket_listen.setNonblocking();
}

Acceptor::~Acceptor()
{

}


void Acceptor::setNewConnectionCallBack(const NewConnectionCallBack& cb)
{
    m_newConnetcionCallBack = cb;
}

void Acceptor::listen()
{
    m_socket_listen.bind();
    m_socket_listen.listen();
    m_channel->enableReading();
    m_eventloop->loop();
}

void Acceptor::handleRead()
{
    struct sockaddr_in conn_addr;
    int conn_sockfd = m_socket_listen.accept(conn_addr);
    if(conn_sockfd < 0)
    {
        return ;
    }
    m_newConnetcionCallBack(conn_sockfd, conn_addr);
}
