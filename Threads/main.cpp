#include <iostream>
#include <thread>
#include <chrono>
//using namespace std;
using namespace std::literals::chrono_literals;

bool finish = false;


void plus()
{
	while (!finish)
	{
		std::cout << "+ ";
		std::this_thread::sleep_for(10ms);
	}
}
void minus()
{
	while (!finish)
	{
		std::cout << "- ";
		std::this_thread::sleep_for(10ms);
	}
}
void main()
{
	//plus();
	//minus();
	std::thread pluse_thread(plus);
	std::thread minus_thread(minus);

	std::cin.get();
	finish = true;

	minus_thread.join();
	pluse_thread.join();
}