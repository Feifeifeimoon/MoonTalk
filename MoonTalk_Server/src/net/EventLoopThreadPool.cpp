#include "EventLoopThreadPool.h"

#include "EventLoop.h"
#include "EventLoopThread.h"

EventLoopThreadPool::EventLoopThreadPool(int nums)
    : m_pthreadnums(nums),
      m_next(0)
{
    
}

EventLoopThreadPool::~EventLoopThreadPool()
{

}

void EventLoopThreadPool::start()
{
    for(int i = 0; i < m_pthreadnums; ++i)
    {
        EventLoopThread* t = new EventLoopThread();
        m_threads.push_back(t);
        m_loops.push_back(t->startLoop());
    }
    printf("ThreadPool Init Done, Threads Nums = %d\n", m_pthreadnums);
}


EventLoop* EventLoopThreadPool::getNextLoop()
{
    EventLoop* loop;
    if(!m_loops.empty())
    {
        loop = m_loops[m_next];
        m_next++;
        if(m_next == m_loops.size())
        {
            m_next = 0;
        }
    }

    return loop;
}