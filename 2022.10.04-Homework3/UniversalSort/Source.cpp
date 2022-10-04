#include<iostream>
#define SWAP(a, b) decltype(a) tmp = a; a = b; b = tmp;

struct Bruh
{
	int a;
	char b;
};
using namespace std;

int main()
{
	Bruh a, b;
	a.a = 2;
	a.b = 'c';
	b.a = 3;
	b.b = 'd';
	cout << a.a << a.b << " " << b.a << b.b << endl;
	SWAP(a, b);
	cout << a.a << a.b << " " << b.a << b.b << endl;


	return EXIT_SUCCESS;
}