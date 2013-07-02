/*
Consider the following structure declaration:

struct customer {
    char fullname[35];
    double payment;
};

Write a program that adds and removes customer structures from a stack, represented by a Stack class declaration.
Each time a customer is removed, his or her payment should be added to a running total, and the running total should be reported.

Note:You should be able to use the Stack class unaltered;
just change the typedef declaration so that Item is type customer instead of unsigned long.
*/
#include "header.h"

int main() {
    Item my_item = {"John Doe", 35000};
    Item my_item2 = {"Jane Doe", 21589};
    Stack my_stack;
    my_stack.showStack();

    my_stack.push(my_item);
    my_stack.push(my_item2);
    my_stack.push(my_item);
    my_stack.showStack();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();

    system("pause");
}