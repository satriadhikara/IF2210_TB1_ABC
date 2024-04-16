#ifndef MATERIAL_PLANT_HPP
#define MATERIAL_PLANT_HPP

#include "Plant.hpp"

class MaterialPlant : public Plant
{
public:
    MaterialPlant(int id, string kodeHuruf, string nama, int price, int durationToHarvest);
    ~MaterialPlant();

    void panen() override;
    string getType() override;
};

#endif