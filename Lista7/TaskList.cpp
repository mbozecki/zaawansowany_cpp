#include "TaskList.h"

TaskList::TaskList(size_t numthreads)
{
	for (size_t i = 0; i < numthreads; i++)
	{
		threads.push_back(thread(&TaskList::func, this, i));
		tasks_to_finish++;
	}
	fun_results.resize(numthreads);
	fill(fun_results.begin(), fun_results.end(), 0);
}

TaskList::~TaskList()
{
}

void TaskList::func(const unsigned int index)
{
	while (!isStopped || !task_queue.empty())
	{
		unique_lock<mutex> mtx_lock(mtx);
		while (task_queue.empty())
		{
			cv.wait(mtx_lock);
		}
		function<double()> fun = task_queue.front();
		task_queue.pop();
		mtx_lock.unlock();
		fun_results[index] += fun();
		no_of_results++;
	}
	tasks_to_finish--;
	cv_stop.notify_one();
}

void TaskList::add_task(function<double()> task)
{
	cout << "add task()\n";
	task_queue.push(task);
	cv.notify_one();
}

double TaskList::average()
{
	double sum = 0;
	for (auto& element : fun_results)
	{
		sum += element;
	}
	return(sum / no_of_results);
}

void TaskList::stop()
{
	cout << "stop()\n";
	isStopped = true;

	cv.notify_all();

	unique_lock<mutex> mtx_lock(mtx);
	while (tasks_to_finish != 0)
	{
		cv_stop.wait(mtx_lock);
	}

	mtx_lock.unlock();

	for (size_t i = 0; i < numthreads; ++i)
	{
		threads[i].join();
		cout << "Thread " << i << " joined\n";
	}
}