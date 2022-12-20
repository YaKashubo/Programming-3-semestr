#include<iostream>
#include<ostream>
#include<fstream>

using namespace std;

template<typename T>
class Vector
{
public:
	T* data;
	int capacity;
	int count;
	void expand(int count = 1);
	int ind(int index);
	void pushend(T element);
	void pushbegin(T element);


	Vector(int capacity = 10);
	Vector(const Vector<T>& list);
	~Vector();

	T& operator[](int pos);

	Vector& operator=(const Vector<T>& list);
	friend std::ostream& operator<<(std::ostream& stream, const Vector<T>& list)
	{
		stream << "[" << list.count << "/" << list.capacity << "] {";
		if (list.count == 0)
		{
			stream << "EMPTY";
		}
		else
		{
			for (int i = 0; i < list.count - 1; ++i)
			{
				stream << list.data[i] << ", ";
			}
			stream << list.data[list.count - 1];
		}
		stream << "}";
		return stream;
	}
};

template<typename T>
void Vector<T>::expand(int count)
{
	T* newdata = new T[count + this->capacity];
	for (int i = 0; i < this->capacity; ++i)
	{
		newdata[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newdata;
	this->capacity += count;
}

template<typename T>
int Vector<T>::ind(int index)
{
	if (index < 0)
	{

		pushbegin(0);
		return 0;
	}
	if (index >= this->count)
	{
		pushend(0);
		return this->count - 1;
	}
	return index;
}

template<typename T>
void Vector<T>::pushend(T element)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}
	this->data[this->count] = element;
	this->count++;
}

template<typename T>
Vector<T>::Vector(int capacity)
{
	this->capacity = capacity;
	this->count = 0;
	this->data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& list)
{
	this->capacity = list.count;
	this->count = list.count;
	this->data = new T[list.count];
	for (int i = 0; i < list.count; ++i)
	{
		this->data[i] = list.data[i];
	}
}

template<typename T>
Vector<T>::~Vector()
{
	this->count = 0;
	this->capacity = 0;
	for (int i = 0; i < this->capacity; ++i)
	{
		this->data[i] = 0;
	}
	delete[] this->data;
}

template<typename T>
void Vector<T>::pushbegin(T element)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}
	for (int i = this->count; i > 0; i--)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[0] = element;
	this->count++;
}

template<typename T>
T& Vector<T>::operator[](int pos)
{
	return data[ind(pos)];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& list)
{
	while (list.capacity > this->capacity)
	{
		expand(this->capacity);
	}
	for (int i = 0; i < list.count; ++i)
	{
		this->data[i] = list.data[i];
	}
	return *this;
}

template<typename T>
void record(Vector<T>& v, string filename)
{
	ofstream f(filename);
	int mem = 0;
	mem = v.count * (sizeof(T));
	f << v.count;
	f.write(reinterpret_cast<char*>(v.data), mem);
	f.close();
}

template<typename T>
Vector<T> readfile(ifstream& f)
{
	int n = 0;
	f >> n;
	Vector<T> v(n);
	int mem = 0;
	mem = n * sizeof(T);
	char* str = new char[mem];
	f.read(str, mem);
	v.count = n;
	v.data = reinterpret_cast<T*>(str);
	
	f.close();
	return v;
}

int main()
{
	
	Vector<int> v1(4);
	Vector<char> v2(3);

	for (int i = 0; i < 4; i++)
		v1[i] = i * 10;

	v2[0] = 'b';
	v2[1] = 'o';
	v2[2] = 'b';

	record(v1, "input1.txt");
	record(v2, "input2.txt");

	ifstream f1("output1.txt");
	ifstream f2("output2.txt");

	cout << readfile<int>(f1) << endl;
	cout << readfile<char>(f2) << endl;

	f1.close();
	f2.close();
	return EXIT_SUCCESS;
}