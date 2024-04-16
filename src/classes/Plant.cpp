#include "Plant.hpp"

Plant::Plant(int id, string kodeHuruf, string nama, int price, int durationToHarvest) : Items(id, kodeHuruf, nama, price)
{
    this->durationToHarvest = durationToHarvest;
    this->age = 1;
}

Plant::~Plant()
{
}

void Plant::setAge(int age)
{
    this->age = age;
}

int Plant::getDurationToHarvest()
{
    return this->durationToHarvest;
}

void Plant::panen()
{
    // TODO
}

bool Plant::isSiapPanen()
{
    return this->age >= this->durationToHarvest;
}