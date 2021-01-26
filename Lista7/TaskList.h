#pragma once
#include <mutex>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <functional>
using namespace std;

class TaskList
{
private:
	size_t numthreads = 0;
	size_t tasks_to_finish = 0;
	int no_of_results = 0;
	bool isStopped = false;
	
	vector<thread> threads;
	vector<double> fun_results;
	queue <function<double()>> task_queue;
	mutex mtx;
	condition_variable cv;
	condition_variable cv_stop;

	void func(const unsigned int index);

public:
	TaskList(size_t numthreads);
	~TaskList();
	void add_task(function<double()> task);
	double average();
	void stop();
};

