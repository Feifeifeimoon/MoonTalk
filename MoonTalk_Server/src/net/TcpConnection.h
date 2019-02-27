#ifndef _MOONTALK_NET_TCPCONNECTION_H_
#define _MOONTALK_NET_TCPCONNECTION_H_

#include "Socket.h"
#include <functional>
#include <memory>
class EventLoop;
class Channel;
class TcpConnection
{
public:
    typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
    typedef std::function<void(TcpConnection&, char*)> MessageCallback;
    typedef std::function<void(TcpConnection&)> CloseCallback;

    TcpConnection(EventLoop* eventloop,int sockfd, struct sockaddr_in addr, const int index);
    ~TcpConnection();
    int index() const { return m_index; }
    struct sockaddr_in addr() const { return m_socket_conn.addr(); }
    void setMessageCallback(const MessageCallback& cb) { m_messageCallback = cb; }
    void setCloseCallback(const CloseCallback& cb) { m_closeCallback = cb;}
    void enableReading();
    void disableReading();
    void enableWriting(); 
    void disableWriting();
    void disableAll();
    void send(char* buf, size_t size);
private:
    void handleRead();
    void handleClose();
private:
    EventLoop*      m_eventloop;
    Socket          m_socket_conn;
    MessageCallback m_messageCallback;
    CloseCallback   m_closeCallback;
    Channel*        m_channel;
    const int       m_index; //use by TcpServer
};


#endif