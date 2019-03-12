#ifndef _MOONTALK_NET_CHANNEL_H_
#define _MOONTALK_NET_CHANNEL_H_


#include <functional>
#include <sys/epoll.h>


class EventLoop;
class Channel
{
public:
    typedef std::function<void()> ReadCallBack;
    typedef std::function<void()> CloseCallback;
    Channel(EventLoop* eventloop, const int sockfd);
    ~Channel();
    int fd() const      { return m_sockfd; }
    int event() const   { return m_events; }
    int index() const   { return m_index; }
    void setIndex(const int index) { m_index = index; }
    void handleEvent();
    void setReadCallBack(const ReadCallBack& cb) { m_ReadCallBack = cb; }
    void setCloseCallBack(const CloseCallback& cb) { m_CloseCallback = cb; }
    void enableReading()    { m_events |= EPOLLIN; update();}
    void disableReading()   { m_events &= EPOLLIN; update();}
    void enableWriting()    { m_events |= EPOLLOUT; update();}
    void disableWriting()   { m_events &= EPOLLOUT; update();}
    void disableAll()       { m_events = 0; update();}
    void update();
    void enadleReading();
private:
    int            m_index;         //use by epoll
    const int      m_sockfd;
    int            m_events;
    ReadCallBack   m_ReadCallBack;
    CloseCallback  m_CloseCallback;
    EventLoop*     m_eventloop;
};

#endif