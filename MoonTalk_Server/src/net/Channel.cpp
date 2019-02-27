#include "Channel.h"
#include "EventLoop.h"

Channel::Channel(EventLoop* eventloop, const int sockfd)
    : m_index(-1),
      m_sockfd(sockfd),
      m_events(0),
      m_eventloop(eventloop)
{

}

Channel::~Channel()
{
    printf("Channel::~Channel()\n");
}


void Channel::handleEvent()
{
    if(m_events == EPOLLIN)
    {
        if(m_ReadCallBack)
            m_ReadCallBack();
    }
    else if( m_events == 0)
    {
        if(m_CloseCallback)
            m_CloseCallback();
    }
    
}


void Channel::update()
{
    m_eventloop->updateChannel(this);
}
