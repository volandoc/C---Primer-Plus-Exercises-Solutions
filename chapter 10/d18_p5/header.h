#include <iostream>
#include <string>

static double running_total = 0;

struct customer {
    char fullname[35];
    double payment;
};

typedef struct customer Item;

class Stack {
private:
    enum {MAX = 10};
    Item stack_[MAX];
    int top_;
    double summ_;
public:
    Stack();

    // constructor with default arguments
    Stack(const Item * [], int n = 0);

    bool isempty() const;
    bool isfull() const;

    // display all information in stack
    void showStack() const;

    // sums Stack values
    void sumStack();

    // pushes one item from stack
    bool push(const Item & item);

    // pops one item from stack
    bool pop();
};