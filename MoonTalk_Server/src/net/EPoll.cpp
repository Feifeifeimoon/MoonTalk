#include "EPoll.h"
#include "Channel.h"
#include <string.h>
#include <algorithm>
#include <memory>

EPoll::EPoll()
    : m_epollfd(::epoll_create1(EPOLL_CLOEXEC)),
      m_eventList(10)
{
}

EPoll::~EPoll()
{

}


void EPoll::poll()
{
    //printf("epoll now have %d events\n", (int)m_eventList.size());
    int events_nums = ::epoll_wait(m_epollfd, &(*m_eventList.begin()), m_eventList.size(), -1);
    if(events_nums < 0)
    {
        perror("epoll wait failed!");
        return ;
    }
    //printf("%d events happend\n", events_nums);
    for(int i = 0; i < events_nums; ++i)
    {
        m_currChannel = (Channel*)m_eventList[i].data.ptr;
        //printf("%d\n", m_currChannel->fd());
        m_currChannel->handleEvent();
    }
    m_currChannel = nullptr;
}

void EPoll::updateChannel(Channel* channel)
{
    //printf("EPoll::updateChannel(Channel* channel)  index = %d  fd = %d\n", channel->index(), channel->fd());
    int index = channel->index();
    int fd = channel->fd();
    ChannelPtr pChannel = std::make_shared<Channel*> (channel);
    if(index == -1)
    {
        m_channelList[fd] = pChannel;
        channel->setIndex(fd);
        update(EPOLL_CTL_ADD, channel);
    }
    else
    {
        int fd = channel->fd();
        m_channelList.erase(fd);
        if(channel->event() == 0)
            update(EPOLL_CTL_DEL, channel);
    }
    //printf("now have %d channel\n", (int)m_channelList.size());
}


void EPoll::update(int operation, Channel* channel)
{
    struct epoll_event event; 
    bzero(&event, sizeof(event));
    event.events = channel->event();
    event.data.ptr = (void*)channel;
    int fd = channel->fd();
    if(::epoll_ctl(m_epollfd, operation, fd, &event) < 0)
    {
        perror("epoll ctl failed");
    }

}


const char* EPoll::operationToString(int operation)
{
    switch(operation)
    {
    case EPOLL_CTL_ADD:
        return "ADD";
    case EPOLL_CTL_DEL:
        return "DEL";
    case EPOLL_CTL_MOD:
        return "MOD";
    default:
        return "EPOLL_CTL_ADD";
    }
}