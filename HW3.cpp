// HW3 abdalrheem hasan salah 12116165

//You are to write a complete C/C++ program that reads a text file full of words. your program should do the followings:

//Find the longest word in the file
//Count number of words that ends with "tion"
//Count number of words that  contains the substring "ie".
//Count number of the word "is".
//Convert words into uppercase letters.
//Note: you should save the above results into  a text file named "results.txt"

#include <iostream>
#include <string>
#include<fstream>
using namespace std;





int main()
{ 
	ifstream a;
	a.open("Text.txt");
	ofstream out;
	out.open("results.txt");
	char* word = NULL;
	word = new char[100];
	char* maxword=NULL;
	int max = 0;
	int count_tion = 0;
	int count_ie = 0;
	int count_is = 0;
	if (a.is_open())
	{
		cout << "text file is open"<<endl;
		while (a >> word)
		{
			if (strlen(word) > max) {
				maxword = new char[strlen(word)];
				strcpy(maxword, word);
				max=strlen(maxword);
			}

			if (strcmp(&word[strlen(word) - 4], "tion") == 0)count_tion++;

			if (strstr(word, "ie")) {
				count_ie++;
			}
			if (strcmp(word, "is") == 0) {
				count_is++;
			}
			out<<_strupr(word)<<" ";
		}
	}
	else
		cout << "text file is not open";
	
	out << endl;
	out << endl;
	if (out.is_open())
	{
		cout << "results file is  open"<<endl;
		out << "longest word text is : "  << maxword<<endl;
		out << "number of words that ends with 'tion' : " << count_tion << endl;
		out << "number of words that  contains the substring 'ie' :  " << count_ie << endl;
		out << "number of words that  contains the substring 'is' : " << count_is << endl;

	}
	else
		cout << "results file is not open"<<endl;

}
