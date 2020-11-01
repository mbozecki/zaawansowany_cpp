#include <iostream>
using namespace std;

// PB: Niepotrzebne kopiowanie - argumenty powinny być przekazane przez stałe referencje
template <typename T1, typename T2>
auto add1(T1 a, T2 b)
{
	return a + b;
}

// PB: Niepotrzebne kopiowanie - argumenty powinny być przekazane przez stałe referencje
template <typename T3, typename T4, typename T5>
auto add2(T3 a, T4 b, T5 f)
{
	return f(a, b);
}

int main()
{
	string x = "XX";
	string y = "YY";

	cout << add1(3.0, 2.19) << endl;
	cout << add1(5, 5) << endl;
	cout << add1(10, 2.5) << endl;
	cout << add1(x, y) << endl;

	cout << add2(5, 8, ([](auto a, auto b) {return a + b; })) << endl;
	cout << add2(4.75, 8.25, ([](auto a, auto b) {return a + b; })) << endl;
	cout << add2(4, 8.25, ([](auto a, auto b) {return a + b; })) << endl;
	cout << add2(x, y, ([](auto a, auto b) {return a + b; })) << endl;
}
