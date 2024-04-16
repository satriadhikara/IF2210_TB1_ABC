#include "HerbivoreAnimal.hpp"

HerbivoreAnimal::HerbivoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest) : Animal(id, kodeHuruf, nama, price, weightToHarvest) {}

HerbivoreAnimal::~HerbivoreAnimal() {}

void HerbivoreAnimal::panen(Matrix<string> &penyimpanan)
{
}

string HerbivoreAnimal::getType()
{
    return "Herbivore";
}