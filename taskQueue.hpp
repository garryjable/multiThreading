#pragma once
#include <queue>
#include "task.hpp"
#include <mutex>
class TaskQueue
{
	public:
		TaskQueue();
		int getTask();

	private:
		std::queue<Task*> m_taskQueue;
		std::mutex m_mutex;

};
