#include "Animal.hpp"

Animal::Animal(int id, string kodeHuruf, string nama, int price, int weightToHarvest) : Items(id, kodeHuruf, nama, price)
{
    this->weightToHarvest = weightToHarvest;
    this->weight = 0;
}

Animal::~Animal() {}

int Animal::getWeightToHarvest()
{
    return this->weightToHarvest;
}

bool Animal::isSiapPanen()
{
    return this->weight >= this->weightToHarvest;
}
void Animal::setBerat(int berat) {
    this->weight = berat;
}