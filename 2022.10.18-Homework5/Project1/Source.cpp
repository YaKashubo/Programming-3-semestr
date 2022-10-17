#include<iostream>
#include "Vector.cpp"

using namespace std;

int main()
{
	Vector<int> list1;
	Vector<int> list2;
	for (int i = 0; i < 10; ++i)
	{
		list1[i] = i;
		list2[i] = 9 - i;
	}

	list1 = list2;
	return 0;
}