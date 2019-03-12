#ifndef _MOONTALK_NET_ACCEPTOR_H_
#define _MOONTALK_NET_ACCEPTOR_H_

#include "Socket.h"
#include <functional>


class EventLoop;
class Channel;
class Acceptor
{
public:
    typedef std::function<void (int,struct sockaddr_in)> NewConnectionCallBack;
    Acceptor(EventLoop* eventloop,const char* ip, const int port);
    ~Acceptor();
    void listen();
    void setNewConnectionCallBack(const NewConnectionCallBack& cb);
private:
    void handleRead();

private:
    EventLoop* m_eventloop;
    Socket m_socket_listen;
    Channel* m_channel;
    NewConnectionCallBack m_newConnetcionCallBack;
};


#endif