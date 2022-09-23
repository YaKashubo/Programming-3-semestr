#include<iostream>
#include "ArrayList.h"

using namespace std;

int main()
{
	ArrayList list, list1;
	for (int i = 0; i < 10; ++i)
	{
		list[i] = i;
		list1[i] = 9 - i;
	}

	cout << "list1 = " << list1 << endl;
	cout << "list = " << list << endl;

	list = list1;
	cout << "new list = " << list << endl;
	return 0;
}