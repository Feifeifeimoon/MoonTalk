#include "EventLoop.h"

#include "EPoll.h"
#include "Channel.h"
EventLoop::EventLoop()
    : m_quit(false),
      m_epoll(new EPoll())
{}


EventLoop::~EventLoop()
{

}

void EventLoop::updateChannel(Channel* channel)
{
    m_epoll->updateChannel(channel);
}

void EventLoop::loop()
{
    m_quit =false;
    while(!m_quit)
    {
        m_epoll->poll();
    }
}