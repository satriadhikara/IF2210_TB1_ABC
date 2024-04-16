#include "OmnivoreAnimal.hpp"

OmnivoreAnimal::OmnivoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest) : Animal(id, kodeHuruf, nama, price, weightToHarvest)
{
}

OmnivoreAnimal::~OmnivoreAnimal()
{
}

void OmnivoreAnimal::panen(Matrix<string> &map)
{
}

string OmnivoreAnimal::getType()
{
    return "Omnivore";
}