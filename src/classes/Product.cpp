#include "Product.hpp"

Product::Product(int id, string kodeHuruf, string nama, int price, string origin, int addedWeight) : Items(id, kodeHuruf, nama, price)
{
    this->origin = origin;
    this->addedWeight = addedWeight;
}

Product::~Product()
{
}

int Product::getAddedWeight()
{
    return this->addedWeight;
}

string Product::getOrigin()
{
    return this->origin;
}