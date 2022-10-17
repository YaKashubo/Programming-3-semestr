#include<iostream>


using namespace std;

class A
{
public:
	int a;
	A(int a = 0) : a(a) {}
	void printA()
	{
		cout << this->a << endl;
	}
	virtual void printCoolerA()
	{
		cout << "Cooler " << this->a << endl;
	}
};
class B: public A
{
public:
	int b;
	B(int b = 0) : b(b) {}
	void printB()
	{
		cout << this->b << endl;
	}

};
int main()
{
	B BB1(228);
	A AA1(322);

	BB1.printA(); 
	cout << BB1.b << endl; 
	cout << BB1.a << endl;

	A *pointerA = &BB1;
	B *pointerB = &BB1;

	pointerA->printCoolerA(); 
	pointerB->printCoolerA();
	pointerA->printA();
	pointerB->printA();
	return EXIT_SUCCESS;
}