// hw4c2lap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
#include <fstream>
using namespace std;
int main()
{
	char* name[4];
	char* name_city[4];
	int grade[4];
	ofstream a;
	for (int i = 0; i < 4; i++)
	{
		name[i] = new char[100];
		name_city[i] = new char[100];
	}
	strcpy(name[0], "Maha");
	strcpy(name[1], "Reema");
	strcpy(name[2], "Rami");
	strcpy(name[3], "Sami");

	grade[0] = 99;
	grade[1] = 77;
	grade[2] = 88;
	grade[3] = 97;
	strcpy(name_city[0], "Nablus");
	strcpy(name_city[1], "Ramallh");
	strcpy(name_city[2], "Jenin");
	strcpy(name_city[3], "Bethlehem");


	a.open("test.txt");
	if (a.is_open()) {
		cout << "file  is open to write ";



		for (int i = 0; i < 4; i++) {
			a << name[i] << " " << grade[i] << " " << name_city[i] << endl;
		}
	}
	else
		cout << "file is not open to write";


	
	char* p;
	int count = 0;
	p = new char[100];
	char* p2;
	p2 = new char[100];
	int grad;
	cin >> p;
	cout << endl;
	cin >> grad;
	cout << endl;

	ifstream b;
	b.open("test.txt");
	if (b.is_open()) {
		cout << "file is open to read";
		string c;
		while (!b.eof()) {
			b >> c;

			while (b.getline(p2, 1000)) {
				count++;
				if (name[count] == p)grade[count] += grad;

			}
		}
	}
	else
		cout << "file is not open to read";


	for (int i = 0; i < 4; i++) {
		a << name[i] << " " << grade[i] << " " << name_city[i] << endl;
	}
	a.close();
	b.close();
}
