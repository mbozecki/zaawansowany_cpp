#include <iostream>
#include <mutex>
#include <future>

using namespace std;
mutex mtx;

int num_thread()
{
	static int num = 0;
	static mutex mtx1;
	num++;
	thread_local int threadnum = [&]() {lock_guard<mutex>lock(mtx1); return num; }();
	return threadnum;
}

void num_and_string(string str)
{
	lock_guard<mutex> lock(mtx);
	cout << num_thread() << " " << str << endl;
}

int run_async(launch asyncpolicy, int num)
{
	if (num > 0)
	{
		num--;
		auto a = async(asyncpolicy, run_async, asyncpolicy, num);
		a.get();
	}
	num_and_string("Printed text ");
	return 0;
}

int main()
{
	auto a =async(launch::async, run_async, launch::async, 6);
	auto b = async(launch::async, run_async, launch::deferred, 6);
}
