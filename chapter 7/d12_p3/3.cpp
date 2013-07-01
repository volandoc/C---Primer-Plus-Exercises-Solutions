/*
Here is a structure declaration:
structure box
	{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
	};

a. Write a function that passes a box structure by value and that displays the value of each member.
b. Write a function that passes the address of a box structure and that sets the volume member to the product of the other three dimensions.
c. Write a simple program that uses these two functions.
*/
#include <iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void pass_by_value( box );
void pass_by_address( box * );
int main ()
{
	box new_box = {"Someone", 452.45, 500.1, 345.1, 0};

	pass_by_value( new_box );
	pass_by_address( &new_box );
	pass_by_value( new_box );
	cout << endl;
	system("pause");
}

void pass_by_value( box new_box )
{
	cout << "new_box.maker: " << new_box.maker << "\nnew_box.height: " << new_box.height << "\nnew_box.lenght: " << new_box.length << "\nnew_box.width: " << new_box.width << "\nnew_box.volume: " << new_box.volume << endl;
}

void pass_by_address( box * new_box )
{
	new_box->volume = new_box->height * new_box->length * new_box->width;
}