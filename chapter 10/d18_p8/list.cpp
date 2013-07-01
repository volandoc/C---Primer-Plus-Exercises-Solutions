#include "list.h"

List::List()
{
	top_ = 0;
}

bool List::isempty() const
{
	return top_ == 0;
}

bool List::isfull() const
{
	return top_ == MAX;
}

// display all information in stack
void List::showList() const
{
	for (int i = 0; i < top_ ; i++)
	{
		std::cout << "Customer " << this->stack_[i].fullname << " payment " << this->stack_[i].payment << std::endl;
	}
}

// adds one item to the end of list
bool List::add(const Item & item)
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

void List::changeName (const int id)
{
	std::cout << "Please, enter new item name: ";
	getline(std::cin, stack_[id-1].fullname);
	std::cout << "Done\n";
};

void List::changeVol (const int id)
{
	std::cout << "Please, enter new item value: ";
	cin >> stack_[id-1].payment;
	std::cout << "Done\n";
};

void List::showItem (const int id)
{
	std::cout << "Your item data: " << stack_[id-1].fullname << " " << stack_[id-1].payment << std::endl;
};