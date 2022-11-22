#include<iostream>
#include"Dictionary.cpp"

using namespace std;

int main()
{
	Dictionary EngAm;
	EngAm.input("lift", "elevator");
	EngAm.input("sweet", "candy");
	EngAm.print();
	
	Dictionary Test;
	Test.read("language.txt");
	Test.translate("initial.txt", "final.txt");

	return EXIT_SUCCESS;
}