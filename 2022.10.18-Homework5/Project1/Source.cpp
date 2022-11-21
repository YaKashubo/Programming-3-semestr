#include<iostream>
#include "Vector.cpp"
#include<ostream>

template<typename T>
class Vector
{
private:
	T* data;
	int capacity;
	int count;
	void expand(int count = 1);
	int ind(int index);
	void pushend(T element);
	void pushbegin(T element);

public:
	Vector(int capacity = 10);
	Vector(const Vector<T>& list);
	~Vector();

	int& operator[](int pos);

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
int& Vector<T>::operator[](int pos)
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

	cout << list1 << endl;
	list1 = list2;
	cout << list1 << endl;
	return 0;
}