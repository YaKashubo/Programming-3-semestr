#include<iostream>
#include<memory>

using namespace std;

struct Server
{

	int players;

	Server(int players = 0)
	{
		this->players = players;
	}
	Server(const Server& s)
	{
		this->players = s.players;
	}
	~Server()
	{
		this->players = 0;
	}
	
};

void work() {};

int main()
{	
	shared_ptr<Server> server1(new Server(10));
	shared_ptr<Server> server2(new Server(10));
	shared_ptr<Server> server3(new Server(10));
	shared_ptr<Server> server4(new Server(10));

	server2 = server1;
	server3 = server1;
	server4 = server1;
	// while there are <5 servers connected with the main server, it will work
	while (server1.use_count() < 5)
	{
		work();
		break;
	}
	cout << server1.use_count() << endl;
	return EXIT_SUCCESS;
}