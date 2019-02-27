#include "EventLoopThread.h"
#include <functional>
#include <sstream>
#include "EventLoop.h"


EventLoopThread::EventLoopThread()
    : m_eventloop(nullptr)
{

}

EventLoopThread::~EventLoopThread()
{
}


EventLoop* EventLoopThread::startLoop()
{
    m_thread = std::thread(std::bind(&EventLoopThread::threadFunc, this));

    {
        std::unique_lock <std::mutex> lck(m_mutex);
        while(m_eventloop == nullptr)
        {
            m_cond.wait(lck);
        }
    }
    return m_eventloop;
}

unsigned int EventLoopThread::getThreadId()
{
    std::ostringstream oss;
	oss << std::this_thread::get_id();
	std::string stid = oss.str();
	unsigned int tid = std::stoull(stid);

}

void EventLoopThread::threadFunc()
{
    EventLoop* loop = new EventLoop();
    {
        std::lock_guard<std::mutex> lck(m_mutex);
        m_eventloop = loop;
        m_cond.notify_all();
    }
    loop->loop();
}

