#pragma once
#include<ostream>
class ArrayList
{
private:
	int* data;
	int capacity;
	int count;
	void expand(int count = 1);
	int ind(int index);
	void pushend(int element);
	void pushbegin(int element);

public:
	ArrayList(int capacity = 10);
	ArrayList(const ArrayList& list);
	~ArrayList();

	int& operator[](int pos);

	ArrayList& operator=(const ArrayList& list);
	friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);

};

