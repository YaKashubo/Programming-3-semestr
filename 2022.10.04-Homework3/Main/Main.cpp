#include<iostream>
#include"Quaternions.h"

using namespace std;

int main()
{
	Q q1,q2(1,-1,1,-1);
	cin >> q1;
	cout << 2 * q1 + 4 * q2<<endl;
	cout << q1 * q2 << endl;
	cout << 1 / q1 << endl;
	cout << q1 / q2 << endl;

	
	return EXIT_SUCCESS;
}