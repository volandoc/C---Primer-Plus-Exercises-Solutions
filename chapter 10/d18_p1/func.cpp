#include <iostream>
#include "header.h"

Account::Account(const std::string & depositor, const std::string & number, double balance) {
    depositor_ = depositor;
    number_ = number;
    balance_ = balance;
}
void Account::Show() const {
    std::cout << "\nDepositor name: " << this->depositor_ << std::endl;
    std::cout << "Depositor account number: " << this->number_ << std::endl;
    std::cout << "Depositor money: " << this->balance_ << std::endl;
}
void Account::deposit( double money ) {
    this->balance_ += money;
    std::cout << "\nMoney added.\n";
}
void Account::withdraw( double money ) {
    this->balance_ -= money;
    std::cout << "\nMoney taken.\n";
}