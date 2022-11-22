#include "Dictionary.h"
#include<iostream>
#include<map>
#include<fstream>
#include<string>

using namespace std;

class Dictionary
{
	map <string, string> dict;
	
public:
	Dictionary(string w1 = " ", string w2= " ")
	{
		dict[w1] = w2;
	}
	Dictionary(const Dictionary& dictionary)
	{
		this->dict = dictionary.dict;
	}
	~Dictionary()
	{		
		dict.erase(dict.begin(), dict.end());
	}

	void input(string w1, string w2)
	{
		dict[w1] = w2;
	}

	void find_by_symbol(char c)
	{
		map<string, string>::iterator it = dict.begin();
		while (it != (dict.end()))
		{
			if (it->first[0] == c)
				cout << it->first << " " << it->second << endl;
			++it;
		}
	}

	void reversed_search(string w)
	{
		map<string, string>::iterator it;
		for (it = dict.end(); it != (dict.begin()); --it)
		{
			if ((it->first == w))
			{
				cout << it->first << "==>" << it->second << endl;
				return;
			}
		}
		cout << "There's no such word in dictionary." << endl;
	}

	void search(string w)
	{
		map<string, string>::iterator it;
		for (it = dict.begin(); it != (dict.end()); ++it)
		{
			if ((it->first == w))
			{
				cout << it->first << " ==> " << it->second << endl;
				return;
			}
		}
		cout << "There's no such word in dictionary." << endl;
	}

	void translate(string ifile, string ofile)
	{
		ifstream inf(ifile);
		ofstream outf(ofile);
		while (!(inf.eof()))
		{
			string w;
			getline(inf, w, ' ');
			outf << dict[w] << " ";
		}
		outf << endl;

		inf.close();
		outf.close();
	}

	void read(string file)
	{
		ifstream f(file);
		while (!(f.eof()))
		{
			string w1, w2;
			getline(f, w1,' ');
			getline(f, w2);
			dict[w1] = w2;
		}
		f.close();
	}
	void print()
	{
		map<string, string>::iterator it;
		for (it = dict.begin(); it != (dict.end()); ++it)
		{
			cout << it->first << " ==> " << it->second << endl;
		}

	}
};
