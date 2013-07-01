#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

#ifndef CUSTOMER_H_  // queue class is reduced to customer class only, since for this
#define CUSTOMER_H_  // programming exercise we'll use STL queue class instead of our own Queue class from Chapter 12
// This queue will contain Customer items
class Customer {
private:
    long arrive; // arrival time for customer
    int processtime; // processing time for customer
public:
    Customer() {
        arrive = processtime = 0;
    }
    void set(long when);
    long when() const {
        return arrive;
    }
    int ptime() const {
        return processtime;
    }
};

inline void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

#endif