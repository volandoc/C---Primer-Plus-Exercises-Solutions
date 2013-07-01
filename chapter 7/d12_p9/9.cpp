/*
This exercise provides practice in writing functions dealing with arrays and structures.
The following is a program skeleton. Complete it by providing the described functions:
*/
#include <iostream>
using namespace std;
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
/*
getinfo() has two arguments:
	a pointer to the first element of an array of student structures
	and an int representing the number of elements of the array.
The function solicits and stores data about students.
It terminates input upon filling the array or upon encountering a blank line for the student name.
The function returns the actual number of array elements filled.
*/
int getinfo(student pa[], int n);

// display1() takes a student structure as an argument and displays its contents 
void display1(student st);

// display2() takes the address of student structure as an argument and displays the structure’s contents
void display2(const student * ps);

// display3() takes the address of the first element of an array of student structures
// and the number of array elements as arguments and displays the contents of the structures
void display3(const student pa[], int n);
int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";

	system("pause");
	return 0;
}

/*
getinfo() has two arguments:
	a pointer to the first element of an array of student structures
	and an int representing the number of elements of the array.
The function solicits and stores data about students.
It terminates input upon filling the array or upon encountering a blank line for the student name.
The function returns the actual number of array elements filled.
*/
int getinfo(student pa[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << "Please, enter student # " << i+1 << " data: ";
		cout << "\nName: ";
		cin.getline(pa[i].fullname, SLEN);
		if ( pa[i].fullname[0] == ' ' || pa[i].fullname[0] == '\0') // not fully clear check, if user enters whitespace and then name - input terminates
			break;
		cout << "Hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "OOP level (integer value): ";
		while (!(cin >> pa[i].ooplevel))
		{
			cin.clear();
			while ( cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
		cin.get(); // clear input
	}
	return i;
}

// display1() takes a student structure as an argument and displays its contents 
void display1(student st)
{
	cout << "\ndisplay1 func output: \n";
	cout << "Student " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOP level: " << st.ooplevel << endl;
}

// display2() takes the address of student structure as an argument and displays the structure’s contents
void display2(const student * ps)
{	
	cout << "\ndisplay2 func output: \n";
	cout << "Student " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "OOP level: " << ps->ooplevel << endl;
}

// display3() takes the address of the first element of an array of student structures
// and the number of array elements as arguments and displays the contents of the structures
void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\ndisplay3 func output: \n";
		cout << "Student " << pa[i].fullname << endl;
		cout << "Hobby: " << pa[i].hobby << endl;
		cout << "OOP level: " << pa[i].ooplevel << endl;
	}
}