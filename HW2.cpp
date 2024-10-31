// Abdalrheem Salah 12116165
//you are to write a complete C / C++ to maintain a list of employees.your program should provide the following operations :
//
//the information about employees should be the followings :
//
//1. employee's name.
//
//2. employee's ID
//
//3. employee's age
//
//4. hours worked per week
//
//5. pay per hour.
//
//6. gross salary.
//
//7. net  salary
//
//8. tax percentage. (5 %, 10 %, 15 %, ..etc..
//
//
//
//    your program should provide the following operations.
//
//    1. read employees data.
//
//    2. display a list of employees.
//
//    3. display an employee with largest gross salary.
//
//    4. display an employee with smallest gross salary.
//
//    5. sort the employees according to their gross salary.
//
//    6. search for a given employee with a given name.
//
//    7.exit

#include <iostream>
#include <string>
//Zc:strictStrings
#pragma warning(disable:4996)

using namespace std;


struct employee {
    char* name;
    int ID;
    int age;
    int hour;
    int pay;
    double grosssalary;
    double netsalary;
    double taxpercentage;

};


void readdata(employee* A, int size);
void display(employee* A, int size);
void getmax(employee* p, int count);
void getmin(employee* x, int count);
void sort(employee* b, int count);
bool search(employee* a, const int count, char* name);


int main()
{
    employee* a;
    char* name = new char[200];
    int size ;
    cout << "input the size : ";
    cin >> size;
    a = new employee[size];

    readdata(a,size);
    cout << "\ndisplay read data  is : \n";
    display(a,size);
    getmax(a, size);
    getmin(a, size);
    cout << endl << endl;
    sort(a, size);
    cout << "\ndisplay sort data  is : \n";
    display(a, size);
    cout << "\nput the name to search in given employee : ";
    cin >> name;
    if (search(a, size, name) == true)
        cout << "true";
    else
        cout << "false";
    exit(0);
}

void readdata(employee* A, int size = 2) {
    char* n = new char[200];
    for(int i=0;i<size;i++){
        cout << "\nenter name :";
        cin >> n;
        A->name = new char[strlen(n) + 1];
        strcpy(A->name, n);
        cout << "\nenter ID :";
        cin >> A->ID;
        cout << "\nenter age :";
        cin >> A->age;
        cout << "\nenter hours worked per week  AND pay :";
        cin >> A->hour >>A->pay;
        A->grosssalary = (A->hour) * (A->pay);
        cout << "\n enter taxpercentage ?";
        cin >> A->taxpercentage;
        A->taxpercentage = A->taxpercentage / 100.0;
        A->netsalary = A->grosssalary * A->taxpercentage;
        A++;
    }

    delete[]n;

}

void display(employee* a,int size=2) {

    for (int i = 0; i < size; i++) {
        cout << "\n name :"<< a->name<< "\t  ID :"<< a->ID<< "\t age :"<< a->age;
        cout << "\n hours worked per week is : " << a->hour << "\tpay is : " << a->pay;
        cout << "\n grosssalary :" << a->grosssalary;
        cout << "\n taxpercentage :"<< a->taxpercentage;
        cout << "\n net salary : " << a->netsalary;
        cout << endl;

        a++;
    }
}

void getmax(employee * p, int count = 2) {
    employee * max = p;
    for (int i = 1; i < count; i++) {
        if (p->grosssalary > max->grosssalary)
            max = p;
        p++;
    }
    cout << "\n name of employee with max grosssalary  : " << max->name << "\tmax grosssalary is :" << max->grosssalary;
}


void getmin(employee* x, int count = 2) {
    employee* min = x;
    for (int i = 0; i < count; i++) {
        if ((x)->grosssalary < min->grosssalary)
        {
            min = x;
            //strcpy(min->name , x->name);
        }
        x++;
    }
    cout << "\n name of employee with min grosssalary  : " << min->name << "\tmin grosssalary is :" << min->grosssalary;
}

void sort(employee* b, int count = 2) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((b+i)->grosssalary>(b+j)->grosssalary) {
                employee T = b[i];
                b[i] = b[j];
                b[j] = T;
            }
        }
    }

}


bool search(employee*a, const int count, char* name) {
    for (int i = 0; i < count ; i++) {
        if (stricmp((a+i)->name, name) == 0)return true;
    }
    return false;

}