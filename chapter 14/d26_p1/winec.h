#include <iostream>
#include <string>
#include <valarray>
#ifndef WINEC_H_
#define WINEC_H_
template <class T1, class T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const {
        return a;
    }
    T2 second() const {
        return b;
    }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first() {
    return a;
}

template<class T1, class T2>
T2 & Pair<T1,T2>::second() {
    return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
private:
    std::string winelabel;
    int years;
    PairArray bt;

public:
    Wine();
    // initialize label to l, number of years to y,
    // vintage years to yr[], bottles to bot[]
    Wine(const char * l, int y, const int yr[], const int bot[]);
    // initialize label to l, number of years to y,
    // create array objects of length y
    Wine(const char * l, int y);
    void GetBottles();
    const std::string & Label() {
        return winelabel;
    }
    int sum() const {
        return bt.second().sum();
    }
    void Show() const;
};

#endif