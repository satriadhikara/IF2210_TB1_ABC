#ifndef FRUIT_PLANT_HPP
#define FRUIT_PLANT_HPP

#include "Plant.hpp"

class FruitPlant : public Plant
{
public:
    FruitPlant(int id, string kodeHuruf, string nama, int price, int durationToHarvest);
    ~FruitPlant();

    void panen() override;
};

#endif