#include <iostream>
#include <mutex>
#include <thread>



int g_num = 0;
std::mutex g_mutex;


void fucn()
{
	for(;;)
	{
		//g_mutex.lock();
		std::lock_guard<std::mutex> lck(g_mutex);
		if(g_num%2 == 0)
			std::cout << ++g_num << std::endl;
		//g_mutex.unlock();
	}
}

void fucn1()
{
	for(;;)
	{
		//g_mutex.lock();
		std::lock_guard<std::mutex> lck(g_mutex);
		if(g_num%2 != 0)
			std::cout << ++g_num << std::endl;
		//g_mutex.unlock();
	}
}

int main()
{
	std::thread th(fucn);
	th.detach();
	std::thread th1(fucn1);
	th1.detach();


	while(1);
}

