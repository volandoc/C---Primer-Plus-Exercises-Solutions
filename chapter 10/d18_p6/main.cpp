/*
Here's a class declaration:

class Move
{
private:
double x;
double y;
public:
Move(double a = 0, double b = 0); // sets x, y to a, b
showmove() const; // shows current x, y values
Move add(const Move & m) const;
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it
reset(double a = 0, double b = 0); // resets x,y to a, b
};

Create member function definitions and a program that exercises the class.
*/
#include "header.h"

int main()
{
	Move my_move1(5.2,.2);
	Move my_move2(1,1);
	my_move1.showmove();
	Move my_move3 = my_move1.add(my_move2);
	my_move1.showmove();
	my_move3.showmove();
	my_move1.reset(0,0);
	system("pause");
}