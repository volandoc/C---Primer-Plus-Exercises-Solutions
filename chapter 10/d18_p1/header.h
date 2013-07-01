#include <string>

class Account
{
private:
	std::string depositor_;
	std::string number_;
	double balance_;
public:
	Account(const std::string & depositor = "no_name", const std::string & number = "no_number", double balance = 0.0);

/*
	// faster type of constructor
	Account ()
		: depositor_("no_name"), number_("no_number"), balance_(.0) {
		depositor_ = depositor;
		number_ = number;
		balance_ = balance;
	}*/
	void Show() const;
	void deposit( double money );
	void withdraw( double money );
};