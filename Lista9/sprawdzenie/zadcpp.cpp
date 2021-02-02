#include <iostream>
void calls1();

class Singleton
{
public:
	static Singleton* instance();
	void calls();
};


int main()
{
	Singleton* s = s->instance();
	s->calls();
	calls1();
}
