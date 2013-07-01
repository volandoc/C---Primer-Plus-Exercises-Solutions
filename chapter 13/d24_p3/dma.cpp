// dma.cpp --dma class methods
#include "dma.h"

ABC_DMA::ABC_DMA(const char *l, int r)
{
    label = new char [std::strlen(l) + 1];
    std::strcpy(label,l);
    rating = r;
}

ABC_DMA::ABC_DMA(const ABC_DMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

ABC_DMA::~ABC_DMA()
{
    delete [] label;
}

ABC_DMA & ABC_DMA::operator=(const ABC_DMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const ABC_DMA & rs)
{
    rs.View();
    return os;
}

void ABC_DMA::View() const
{
    std::cout << "\nLabel: " << label;
    std::cout << "\nRating: " << rating;
}

baseDMA::baseDMA(const char * l, int r) : ABC_DMA(l,r)
{

}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABC_DMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}
lacksDMA::lacksDMA(const char * c, const ABC_DMA & rs) : ABC_DMA(rs)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

void lacksDMA::View() const
{
    ABC_DMA::View();
    std::cout << "\nColor: " << color;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r) : ABC_DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const char * s, const ABC_DMA & rs) : ABC_DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs) : ABC_DMA(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
    delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    ABC_DMA::operator=(hs); // copy base portion
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
void hasDMA::View() const
{
    ABC_DMA::View();
    std::cout << "\nStyle: " << style;
}