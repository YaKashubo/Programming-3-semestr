#include <iostream>

using namespace std;

class Tester
{
	friend struct Toster;
	int a;
	void print_a()
	{
		cout << this->a << endl;
	}
};
struct Toster
{
	void print(Tester t)
	{
		void (Tester:: * pointer)() = &Tester::print_a;
		(t.*pointer)();
	}
	void swapper(Tester& t, int a)
	{
		t.a = a;
	}
};
int main() 
{
	Tester test;
	Toster tost;

	tost.swapper(test, 228);
	tost.print(test);

	return EXIT_SUCCESS;
}