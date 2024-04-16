#include "FruitPlant.hpp"

FruitPlant::FruitPlant(int id, string kodeHuruf, string nama, int price, int durationToHarvest) : Plant(id, kodeHuruf, nama, price, durationToHarvest) {}

FruitPlant::~FruitPlant() {}

string FruitPlant::getType() { return "Fruit"; }

void FruitPlant::panen() {}