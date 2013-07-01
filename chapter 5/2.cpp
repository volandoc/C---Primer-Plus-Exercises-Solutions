/*
Redo Listing 5.4 using a type array object instead of a built-in array
and type long double instead of long long. Find the value of 100!

Listing 5.4:
#include <iostream>
const int ArSize = 16;

int main ()
{
	long long factorials[ArSize];
	factorials[0] = factorials[1] = 1;

	for ( int i = 2; i < ArSize; i++ )
	{
		factorials[i] = i * factorials[i-1];
	};

	for ( i = 0; i < ArSize; i++ )
	{
		std::cout << i << "!= " << factorials[i] << std::endl;
	};
	return 0;
}
I Found an error in listing in book 17 line - "i" is not declared as int,
instead "for ( i = 0; i < ArSize; i++ )" need to write "for ( int i = 0; i < ArSize; i++ )"*/

#include <iostream>
#include <array>


const int ArSize = 101;

int main ()
{
	std::array <long double, ArSize> factorials;
	factorials[0] = factorials[1] = 1;

	for ( int i = 2; i < ArSize; i++ )
	{
		factorials[i] = i * factorials[i-1];
	};

	for ( int i = 0; i < ArSize; i++ )
	{
		std::cout << i << "!= " << factorials[i] << std::endl;
	};
	system("pause");
	return 0;
}