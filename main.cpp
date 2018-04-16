#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <functional>

#include "computePi.hpp"
#include "task.hpp"
#include "taskQueue.hpp"
#include "map.hpp"


void threadWorker(std::uint16_t threadNum, TaskQueue& taskQueue, Map& map) {
#warning TODO: This function will take a reference to the FIFO task queue as an argument
#warning TODO: This function will take a reference to your unordered_map as an argument

	//NOTE I can't get the reference pass to work so I am going to write up other code for now.
	for(int i = 0; i < 250 ; i++)
	{
	std::cout<< '.' << std::flush;
	int n  = taskQueue.getTask();
	int digit = computePiDigit(n);
	map.writeMap(n, digit);	
	}
}



int main() {
#warning TODO: Initialize your thread-safe data structures here
	TaskQueue taskQueue;
	Map map;
	//
	// Make as many threads as there are CPU cores
    // Assign them to run our threadWorker function, and supply arguments as necessary for that function
	std::vector<std::shared_ptr<std::thread>> threads;
	for (std::uint16_t core = 0; core < std::thread::hardware_concurrency(); core++)
        // The arguments you wish to pass to threadWorker are passed as
        // arguments to the constructor of std::thread
		threads.push_back(std::make_shared<std::thread>(threadWorker, core, std::ref(taskQueue), std::ref(map)));  //inspiration from jakascorner.com/blog/2016/01/arguments.html

	//
	// Wait for all of these threads to complete
	for (auto&& thread : threads)
		thread->join();

	std::cout << std::endl << std::endl;

#warning TODO: Print the digits of PI from our unordered_map, in order
	std::cout << "3." ;
	for(int i = 1; i <=1000; i++)
	{
		std::cout << map.readMap(i);
	}
	std::cout << std::endl;
	return 0;
}
