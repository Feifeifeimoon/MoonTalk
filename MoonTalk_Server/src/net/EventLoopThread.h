#ifndef _MOONTALK_NET_EVENTLOOPTHREAD_H_
#define _MOONTALK_NET_EVENTLOOPTHREAD_H_

#include <thread>
#include <mutex>
#include <condition_variable> 

class EventLoop;
class EventLoopThread
{
public:
    EventLoopThread();
    ~EventLoopThread();
    EventLoop* startLoop();
    unsigned int getThreadId();
private:
    void threadFunc();
private:
    EventLoop*              m_eventloop;
    std::thread             m_thread;
    std::mutex              m_mutex;
    std::condition_variable m_cond;
};


#endif