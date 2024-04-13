#include "FruitPlant.hpp"

FruitPlant::FruitPlant(int id, string kodeHuruf, string nama, int price, int durationToHarvest) : Plant(id, kodeHuruf, nama, price, durationToHarvest) {}

FruitPlant::~FruitPlant() {}

void FruitPlant::panen() {}