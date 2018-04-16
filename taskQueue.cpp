#include "taskQueue.hpp"

TaskQueue::TaskQueue()
{
	for(int i = 1 ; i <= 1000 ; i++)
	{
		Task* task = new Task(i);
		m_taskQueue.push(task);	
		task = nullptr;
	}

}


int TaskQueue::getTask()
{
	Task* task;
	m_mutex.lock();
	task = m_taskQueue.front();
	m_taskQueue.pop();
	m_mutex.unlock();
	int digit = task->getDigit();
	delete task;
	return digit;
}
