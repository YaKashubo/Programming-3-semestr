#include<iostream>

using namespace std;

template<typename T>
void universal_sort(T* a, int n, int(*cmp)(T p1, T p2), void (*sort)(T* a, int n, int(*comparator)(T p3, T p4)) = nullptr)
{
	if (sort != nullptr)
	{
		sort(a, n, cmp);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (cmp(a[i], a[j]) > 0)
				{
					T temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
}

template<typename T>
void print(T* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
template<typename T>
void monkeysort(T* a, int n, int(*comparator)(T p3, T p4))
{
	bool isSorted = false;
	while (!isSorted)
	{
		for (int i = 0; i < n; i++)
		{
			int randInd1 = rand() % n;
			int randInd2 = rand() % n;
			T temp = a[randInd2];
			a[randInd2] = a[randInd1];
			a[randInd1] = temp;

		}
		for (int i = 0; i < n - 1; i++)
		{
			if (comparator(a[i], a[i + 1]) < 0)
			{
				isSorted = false;
				break;
			}
			isSorted = true;
		}
	}


}
int comparator(int p1, int p2)
{
	return p1 - p2;
}
int cmpSTR(string p1, string p2)
{
	return p1.length() - p2.length();
}
int main(int argc, char* argv[])
{
	int a[4];
	for (int i = 0, j = 4; i < 4 && j >= 0; ++i, --j)
	{
		a[i] = i * j;
	}

	print<int>(a, (sizeof(a) / sizeof(a[0])));
	universal_sort<int>(a, (sizeof(a) / sizeof(a[0])), comparator,monkeysort);
	print<int>(a, (sizeof(a) / sizeof(a[0])));

	string b[3]{ "cringe","lol", "rofl" };
	print<string>(b, 3);
	universal_sort(b, 3, cmpSTR);
	print<string>(b, 3);

	return EXIT_SUCCESS;
}