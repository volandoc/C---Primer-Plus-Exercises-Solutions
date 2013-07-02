#include <iostream>
#include <string>
#include "header.h"
using namespace std;
int main() {
    cout << "Setting object with constructor by default.";
    Account my_account;
    my_account.Show();

    cout << "\nSetting object with parameters.\n";
    string s = "John Doe";
    Account my_account2("John Doe", "123456", 25000);
    my_account2.Show();

    my_account2.deposit(20000);
    my_account2.Show();
    my_account2.withdraw(12567);
    my_account2.Show();
    system("pause");
}