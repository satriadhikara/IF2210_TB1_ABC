#include "OmnivoreAnimal.hpp"

OmniVoreAnimal::OmniVoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest) : Animal(id, kodeHuruf, nama, price, weightToHarvest)
{
}

OmniVoreAnimal::~OmniVoreAnimal()
{
}

void OmniVoreAnimal::panen(Matrix<string> &map)
{
}