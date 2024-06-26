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

void Animal::setWeight(int weight)
{
    this->weight = weight;
}

bool Animal::isSiapPanen()
{
    return this->weight >= this->weightToHarvest;
}