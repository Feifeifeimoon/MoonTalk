#ifndef _MOONTALK_NET_EVENTLOOP_H_
#define _MOONTALK_NET_EVENTLOOP_H_


class EPoll;
class Channel;
class EventLoop
{
public:
	EventLoop();
	~EventLoop();
	void loop();
	void updateChannel(Channel* channel);
private:
	bool   m_quit;
	EPoll* m_epoll;
	
};



#endif