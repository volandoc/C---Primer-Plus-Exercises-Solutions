#include "header.h"

Stack::Stack()
{
	top_ = 0;
}

// constructor with default arguments
Stack::Stack(const Item * it[], int n)
{
	if (n==0)
		top_ = 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			stack_[i] = * it[i];
			top_++;
		}
	}
}

bool Stack::isempty() const
{
	return top_ == 0;
}

bool Stack::isfull() const
{
	return top_ == MAX;
}

// display all information in stack
void Stack::showStack() const
{
	for (int i = 0; i < top_ ; i++)
	{
		std::cout << "Customer " << this->stack_[i].fullname << " payment " << this->stack_[i].payment << std::endl;
	}
}

// sums Stack values
void Stack::sumStack()
{
	this->summ_ = 0;
	for (int i = 0; i < top_ ; i++)
	{
		this->summ_ += this->stack_[i].payment;
	}
	std::cout << "Average stack summation: " << this->summ_ << std::endl;
}

// pushes one item from stack
bool Stack::push(const Item & item)
{
	if (this->top_ < MAX)
	{
		this->stack_[this->top_++] = item;
		return true;
	} 
	else
	{
		return false;
	}
}
// pops one item from stack
bool Stack::pop()
{
	if (this->top_ > 0)
	{
		running_total += this->stack_[--this->top_].payment;
		std::cout << "Running total: " << running_total << std::endl;
		return true;
	} 
	else
	{
		return false;
	}
}