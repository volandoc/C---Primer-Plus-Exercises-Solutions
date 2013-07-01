// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>
#include <cstring>

class ABC_DMA {
private:
    char * label;
    int rating;
public:
    ABC_DMA(const char * l = "null", int r = 0);
    ABC_DMA(const ABC_DMA & rs);
    virtual ~ABC_DMA();
    ABC_DMA & operator=(const ABC_DMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const ABC_DMA & rs);
    virtual void View() const = 0; // pure virtual function, thus making ABC_DMA an abstract base class
};


class baseDMA : public ABC_DMA {
public:
    baseDMA(const char * l = "null", int r = 0);
    void View() const {
        ABC_DMA::View();
    }

};


class lacksDMA : public ABC_DMA {
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const ABC_DMA & rs);
    void View() const;
};


class hasDMA : public ABC_DMA {
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const ABC_DMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA(); // own special destructor is needed for DMA item style
    hasDMA & operator=(const hasDMA & rs);
    void View() const;
};
#endif