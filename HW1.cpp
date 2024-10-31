// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//You are to write a complete C/C++ program to maintain a list of student names dynamically. The user should be allowed to enter number of students.

//student names should be declared  as follows :
//
//char** names = NULL;
//
//int  Count = 0;   // MUST be  entered by the user.
//
//cout << "Enter number of names";
//
//cin >> count;
//
//names = new char* [count];    this will define a multi - dimensional array with variable number of rows and columns.
//
//Your program should provide a set of operations.each operation should be written as a function :
//
//1.  read names  from keyboard and store them into the array names.
//
//2. sort the array in ascending order display on screen.
//
//3. sort the array in ascending order according to the length of names and then display.
//
//4. find the name with the largest number of  'a' in it.
//
//5. search for a given name, provided by the user.,
//
//6. Capitalized all names and show on screen.
//
//7. find the longest and shortest name.
//
//8. delete the array names
//
//9. exit the program.



#include <iostream>
#include <string>
//Zc:strictStrings
#pragma warning(disable:4996)

using namespace std;

void read(char* a[], const int count) {
	int i = 0;

	while (i != count) {
		a[i] = new char[100];
		cin >> a[i];
		i++;
	}

}
void sort(char* a[], const int count) {
	 int i;
	 
	 for (int i = 0; i < count-1; i++)
	 {
		 for (int j = i+1; j < count; j++)
		 {
			
				 if (stricmp(a[i],a[j])>0)
				 {
					 char* temp;
					 temp = a[i];
					 a[i] = a[j];
					 a[j] = temp;

				 }
		 }
	 }
}
void sort_len(char* a[],const int count) {
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (strlen(a[i]) > strlen(a[j]))
			{
				char* temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

char * find( char* a[], const int count,char ch) {
	int i = 0;
	char* myStr=new char[count]; 
	  int count2 = 0;
	  int countmax = 0;
	  char* pmax=new char[100];
	for (int i = 0; i < count ; i++)
	{
		count2 = 0;
		const char* ptr = a[i];
		while ((ptr = strchr(ptr, ch)) != NULL) {
			count2++;
			ptr++;
		}
		if (count2 > countmax) { countmax = count2; 
		pmax = a[i];
		}
	}
	return pmax;
}
bool search(char* a[], const int count,char *name) {
	for (int i = 0; i < count-1; i++) {
		if (strcmp(a[i], name) == 0)return true;
	}
	return false;

}
void capitaliz(char* a[], const int count) {
	for (int i = 0; i < count; i++) {
		strupr(a[i]);
	}

}


char* shortest_longest(char* a[], const int count) {
	char* b[2];
	sort_len(a, count);
	b[0] = a[0];
	b[1] = a[count-1];
	return strcat(b[0],b[1]);
}
void del(char* a[]) {
		delete []a;
	
}
void display(char* a[], const int count) {
	for (int i = 0; i < count; i++) {
		cout << a[i]<<endl;
	}

}

int main()
{
	char** names = NULL;
	int count = 0;
	cout << "Enter number of names ";
	cin >> count;
	names = new char* [count];
	char ch;
	char* name=new char[100];
	while (true) {
		int x;
		cout <<endl<< "1: read value" << endl;
		cout << "2: sort value with char" << endl;
		cout << "3: sort value with length" << endl;
		cout << "4: char to search" << endl;
		cout << "5: name to search" << endl;
		cout << "6: capitaliz" << endl;
		cout << "7: shortest_longest (with strcat return together)" << endl;
		cout << "8: delete" << endl;
		cout << "9: exit" << endl;

		cin >> x;
		switch (x) {
		case 1:
		{
			read(names, count);
			cout << "display read value" << endl;
			display(names, count);
			break;
		}
		case 2: {
			sort(names, count);
			cout << "display sort value with char " << endl;
			display(names, count);
			break;

		}
		case 3: {
			sort_len(names, count);
			cout << "display sort value with length " << endl;
			display(names, count);
			break;

		}
		case 4:{
			cout << "enter the char to search " << endl;
			cin >> ch;
			cout<<find(names, count, ch);
			break;
		}
		case 5: {
			cout << "enter the name to search " << endl;
			cin >> name;
			cout << search(names, count, name) << endl;
			break;

		}
		case 6: {
			cout << "capitaliz " << endl;
			capitaliz(names, count);
			display(names, count);
			break;

		}
		case 7: {
			cout << "shortest_longest (with strcat return together) " << endl;
			cout << shortest_longest(names, count);
			break;

		}
		case 8: {	del(names);
			cout << " deleted" << endl;
			break;

		}
		case 9: { exit(0);
		}
		}
	}

}


