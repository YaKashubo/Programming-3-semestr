#include<iostream>
#include<fstream>
#include <string>

using namespace std;

int main()
{
	ifstream f("data.txt");
	int n = 0;
	try
	{
		if (!(f.is_open()))	throw "file didn't open.";
		else
		{
			f >> n;
			if (n <= 0 || (typeid(n) != typeid(int)))
			{
				throw "wrong array's range.";
			}
			int* a = new int[n];
			int realn = 0;
			for (int i = 0; i < n; ++i)
			{
				string s;
				f >> s;
				if (!(s.find_first_not_of("-0123456789") == string::npos)) throw "wrong type of element.";
				a[i] = stoi(s);
				realn++;
			}
			if (realn == 0) throw "empty array.";
			else
			{
				double ratio = 0;
				double geomMean = 0.0;
				int sum = 0;
				for (int i = 0; i < realn - 1; ++i)
				{
					if (long long(sum + a[i]) > pow(2, 8 * sizeof(int))) throw "type overflow.";
					else sum += a[i];
					if (realn == 1) throw "out of array's range.";
					else
					{
						if (a[i + 1] == 0) throw "dividing by 0.";
						ratio += (a[i] / a[i + 1]);
					}
					if (a[i] <= 0) throw "math logic error.";
					else geomMean += log(a[i]);
				}
				sum += a[realn - 1];
				geomMean += log(a[realn - 1]);
				ratio /= realn;
				geomMean = exp((geomMean / realn));
				cout << "Summary of array is " << sum << endl;
				cout << "Geometric mean of array is " << geomMean << endl;
				cout << "Avarage ratio of array's element is " << ratio << endl;
			}
		}
	}
	catch (const char* msg)
	{
		cerr << "Error: " << msg << endl;
	}
	f.close();
	return EXIT_SUCCESS;
}

