#ifndef _MOONTALK_NET_EPOLL_H_
#define _MOONTALK_NET_EPOLL_H_

#define MAX_EVENTS 20

#include <stdio.h>
#include <vector>
#include <map>
#include <memory>			//std::shared_ptr
#include <unistd.h>
#include <sys/epoll.h>



class Channel;
class EPoll
{
public:
    typedef std::shared_ptr<Channel*> ChannelPtr;
    EPoll();
    ~EPoll();
    void poll();
    void updateChannel(Channel* pChannel);

private:
    void update(int operation, Channel* channel);
    const char* operationToString(int operation);
private:
    int m_epollfd;
    std::vector<struct epoll_event> m_eventList;
    std::map<int, ChannelPtr>       m_channelList;
    Channel*                        m_currChannel;
};



#endif