#include "MaterialPlant.hpp"

MaterialPlant::MaterialPlant(int id, string kodeHuruf, string nama, int price, int durationToHarvest) : Plant(id, kodeHuruf, nama, price, durationToHarvest) {}

MaterialPlant::~MaterialPlant() {}

void MaterialPlant::panen() {}