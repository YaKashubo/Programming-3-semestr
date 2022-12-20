#include<iostream>

using namespace std;

struct Door
{
	void open()
	{
		cout << "����������" << endl;
	}

	void close()
	{
		cout << "����������" << endl;
	}
};

class Security
{
protected:
	Door door;

public:
	Security(Door door)
	{
		this->door = door;
	}

	void open(string password)
	{
		if (authenticate(password)) {
			this->door.open();
		}
		else {
			cout << "��� ����������" << endl;
		}
	}

	bool authenticate(string password)
	{
		return (password == "$ecr@t");
	}

	void close()
	{
		this->door.close();
	}
};

int main()
{
	Door labdoor();
	Security door(Door labdoor);
	door.open("invalid");	// ��� ����������
	door.open("$ecr@t");	// ����������
	door.close();			// ����������
	return EXIT_SUCCESS;
}