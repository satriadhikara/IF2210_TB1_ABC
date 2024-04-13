#include "CarnivoreAnimal.hpp"

CarnivoreAnimal::CarnivoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest) : Animal(id, kodeHuruf, nama, price, weightToHarvest) {}

CarnivoreAnimal::~CarnivoreAnimal() {}

void CarnivoreAnimal::panen(Matrix<string> &penyimpanan)
{
}
