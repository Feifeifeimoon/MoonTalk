#ifndef _MOONTALK_NET_EVENTLOOPTHREADPOOL_H_
#define _MOONTALK_NET_EVENTLOOPTHREADPOOL_H_

#include <vector>

class EventLoop;
class EventLoopThread;

class EventLoopThreadPool
{
public:
    EventLoopThreadPool(int nums);
    ~EventLoopThreadPool();
    void start();
    EventLoop* getNextLoop();
private:
    int                           m_pthreadnums;
    int                           m_next;
    std::vector<EventLoopThread*> m_threads;
    std::vector<EventLoop*>       m_loops;
};


#endif 