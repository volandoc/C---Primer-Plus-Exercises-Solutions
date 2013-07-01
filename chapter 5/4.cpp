/*
Daphne invests $100 at 10% simple interest.
That is, every year, the investment earns 10% of the original investment,
or $10 each and every year:
interest = 0.10 x original balance

At the same time, Cleo invests $100 at 5% compound interest.
That is, interest is 5% of the current balance,
including previous additions of interest:

interest = 0.05 x current balance

Cleo earns 5% of $100 the first year, giving her $105.
The next year she earns 5% of $105, or $5.25, and so on.

Write a program that finds how many years it takes for the value of Cleo’s investment
to exceed the value of Daphne’s investment and then displays the value of both investments at that time.
*/

#include <iostream>
using namespace std;
int main ()
{	
	float daphie_invest,cleo_invest;
	daphie_invest = cleo_invest = 100.0;
	int years = 0;
	do 
	{
		daphie_invest += 10.0;
		cleo_invest *= 1.05;
		years++;
	} while (daphie_invest > cleo_invest);
	
	
	cout << "Cleo wins in " << years << " years." << endl;
	
	system("pause");
}