//Implement a struct Account. An account has

//a balance variable,
//functions to add and withdraw (سحب) money,
//and a function to inquire (استعلام) the current balance.
//Instantiate an object of type Account and initialize the balance member with any value.

//Charge a $5 penalty (عقوبة) if an attempt is made to withdraw more money than available in the account.

#include <iostream>
#include<math.h>
#include<string.h>


using namespace std;

struct Account {

	double balance;
	Account() {
		balance = 10;
	}
void withdraw(double value) {
	cout << "press a if wont add and w if wont to withdraw  ";
	char x;
	cin >> x;
	if (x == 'a') {
		balance += value;
	}
	if (x == 'w') {
		if (balance > value)
			balance -= value;
		else if (balance < value)
			balance -= 5;
	}
}

int inquire() {
	return balance;
}
};

int main()
{
	Account a;
	int x, value;
	cout << "press 1 if wont (add or withdraw) and 2 for inquire  ";
	cin >> x;
	while (true)
	{
	switch (x)
	{
	case 1:
	{
		cout << "input value to do (add or withdraw) ";
		cin >> value;
		a.withdraw(value);
		cout << "balance is:" << a.inquire() << endl;;
		break;
	}
	case 2: {
		cout <<"balance is:" << a.inquire() << endl;;
		break;


	}
	case 0:
	{	exit(0);
	break;
	}
	default:
	{
		cout << "press 1 if wont (add or withdraw) and 2 for inquire  ";
		cin >> x;
		break;
	}
	}

	cout << "press 1 if wont (add or withdraw) and 2 for inquire  ";
	cin >> x;
}
}


