#include <iostream>
using namespace std;

// PB: Mimo, że da się osiągnąć oczekiwany wynik stosując fold expression,
//     to poprawne rozwiązanie powinno zawierać użycie ‘constexpr if’ oraz operatora ’sizeof…’
template <typename ...Args>
auto add(Args ...args)
{
	return (0.0 + ... + args);
}

int main()
{
	cout << add(1, 2.13f, 2.11,0.00001,3)<< endl;

}
