#include<iostream>
#include<fstream>
#include <string>

using namespace std;

int main()
{
	ifstream f("data.txt");
	int n = 0;
	f >> n;

	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		f >> a[i];
	}

	double ratio = 0;
	double geomMean = 0.0;
	int sum = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		sum += a[i];
		ratio += (a[i] / a[i + 1]);
		geomMean += log(a[i]);
	}
	sum += a[n - 1];
	geomMean += log(a[n - 1]);

	ratio /= n;
	geomMean = exp((geomMean / n));

	cout << "Summary of array is " << sum << endl;
	cout << "Geometric mean of array is " << geomMean << endl;
	cout << "Avarage ratio of array's element is " << ratio << endl;

	f.close();
	return EXIT_SUCCESS;
}

