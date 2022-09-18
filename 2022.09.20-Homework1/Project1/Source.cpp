#include <iostream>

using namespace std;

struct Testmax
{
	// 48 byte(32 byte + 16 byte)
	char c; //			1 byte
	long long ll; //	8 byte
	bool b; //			1 byte
	double d; //		8 byte
	short s; //			2 byte
	int i; //			4 byte
	long l; //			4 byte
	float f; //			4 byte
};

struct Testmin
{
	// 32 byte(32 byte + 0 byte)
	long long ll; //	8 byte
	double d; //		8 byte
	int i; //			4 byte
	long l; //			4 byte
	float f; //			4 byte
	short s; //			2 byte
	char c; //			1 byte
	bool b; //			1 byte
};
int main()
{
	Testmax one;
	cout << sizeof(one) << endl;
	cout << (int*)&one.c <<" "<<sizeof(one.c)<< endl;
	cout << &one.ll<< " "<<sizeof(one.ll)<<endl;
	cout << &one.b << " "<<sizeof(one.b)<<endl;
	cout << &one.d << " "<<sizeof(one.d)<<endl;
	cout << &one.s << " "<<sizeof(one.s)<<endl;
	cout << &one.i << " "<<sizeof(one.i)<<endl;
	cout << &one.l << " "<<sizeof(one.l)<<endl;
	cout << &one.f << " "<<sizeof(one.f)<<endl;

	Testmin two;
	cout << sizeof(two) << endl;	
	cout << &two.ll << " " << sizeof(two.ll) << endl;
	cout << &two.d << " " << sizeof(two.d) << endl;
	cout << &two.i << " " << sizeof(two.i) << endl;
	cout << &two.l << " " << sizeof(two.l) << endl;
	cout << &two.f << " " << sizeof(two.f) << endl;
	cout << &two.s << " " << sizeof(two.s) << endl;
	cout << (int*)&two.c << " " << sizeof(two.c) << endl;
	cout << &two.b << " " << sizeof(two.b) << endl;
	return EXIT_SUCCESS;

	/*
	*  ѕам€ть выдел€етс€ так, чтобы адрес переменной делилс€ размер выдел€емой пам€ти еЄ типа(на sizeof()).
	*  ƒл€ этого к предыдущей переменной прибавл€ют недостающее количество бит так, что адрес нынешней переменной 
	*  соответствовал условию.
	*  https://learn.microsoft.com/ru-ru/cpp/cpp/alignment-cpp-declarations?view=msvc-170
	*/
}