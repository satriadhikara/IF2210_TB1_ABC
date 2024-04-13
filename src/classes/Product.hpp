#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Items.hpp"

class Product : public Items
{
private:
    string origin;
    int addedWeight;

public:
    Product(int id, string kodeHuruf, string nama, int price, string origin, int addedWeight);
    ~Product();

    int getAddedWeight();
    string getOrigin();
};

#endif