#include <iostream>
#include "TaskList.h"
using namespace std;

double fun1()
{
	double num = 0;
	for (int i = 0; i < 200; i++)
	{
		num -= 3.14;
	}
	return num;
}

double fun2()
{
	double num = 0;
	for (int i = 0; i < 100; i++)
	{
		num += 1.71;
	}
	return num;
}

int main()
{
	TaskList taskList(5);

	taskList.add_task(fun1);
	taskList.add_task(fun1);
	taskList.add_task(fun2);
	taskList.add_task(fun2);
	taskList.stop();
	cout << "Average: " << taskList.average() << endl;
	getchar();

	return 0;
}