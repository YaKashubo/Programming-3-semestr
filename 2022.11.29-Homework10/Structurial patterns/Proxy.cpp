#include<iostream>

using namespace std;

struct Door
{
	void open()
	{
		cout << "Открывание" << endl;
	}

	void close()
	{
		cout << "Закрывание" << endl;
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
			cout << "Это невозможно" << endl;
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
	door.open("invalid");	// Это невозможно
	door.open("$ecr@t");	// Открывание
	door.close();			// Закрывание
	return EXIT_SUCCESS;
}