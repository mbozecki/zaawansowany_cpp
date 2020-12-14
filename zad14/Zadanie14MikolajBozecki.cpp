
#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <string>

using namespace std;

void iloczyn_skalarny(vector<double> vec1, vector<double> vec2, promise <double>& prms)
{
	try
	{
		if (vec1.size() != vec2.size()) throw invalid_argument(string("Inny rozmiar wektorow"));
		double iloczyn = 0;
		for (int i = 0; i < vec1.size(); i++)
		{
			iloczyn += (vec1[i] * vec2[i]);
		}
		prms.set_value((iloczyn));
	}
	catch (...)
	{
		prms.set_exception(std::current_exception());
	}
	
}
int main()
{
	vector<double> vec1 = { 1,2 };
	vector<double> vec2 = { 3,4 };
	vector<double> vec3 = { 5,10,15 };
	vector<double> vec4 = { 10,20,30 };
	vector<double> vec5 = { 1,2,3 };
	vector<double> vec6 = { 8,9 };
	vector<double> vec7 = { 0,0 };

	promise<double> prms_arr[10];

	thread th1(iloczyn_skalarny, vec1, vec2, std::ref(prms_arr[0]));
	thread th2(iloczyn_skalarny, vec3, vec4, std::ref(prms_arr[1]));
	thread th3(iloczyn_skalarny, vec4, vec5, std::ref(prms_arr[2]));
	thread th4(iloczyn_skalarny, vec1, vec6, std::ref(prms_arr[3]));
	thread th5(iloczyn_skalarny, vec1, vec4, std::ref(prms_arr[4]));
	thread th6(iloczyn_skalarny, vec1, vec3, std::ref(prms_arr[5]));
	thread th7(iloczyn_skalarny, vec6, vec7, std::ref(prms_arr[6]));
	thread th8(iloczyn_skalarny, vec3, vec6, std::ref(prms_arr[7]));
	thread th9(iloczyn_skalarny, vec1, vec7, std::ref(prms_arr[8]));
	thread th10(iloczyn_skalarny, vec2, vec6, std::ref(prms_arr[9]));

	future<double> fut_arr[10];
	for (int i = 0; i < 10; i++)
	{
		fut_arr[i]=prms_arr[i].get_future();

		try {
			cout << fut_arr[i].get() << endl;
		}
		catch (std::exception & e) {
			cout << "Blad. :" << e.what() << "\n";
		}
	}

	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();
	th7.join();
	th8.join();
	th9.join();
	th10.join();

}

