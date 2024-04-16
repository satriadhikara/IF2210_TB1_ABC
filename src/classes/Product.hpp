#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Items.hpp"

class Product : public Items
{
private:
    string origin;
    string type;
    int addedWeight;

public:
    Product(int id, string kodeHuruf, string nama, string type, int price, string origin, int addedWeight);
    ~Product();

    int getAddedWeight();
    string getOrigin();
    string getType() const {
        return type;
    }
};

#endif