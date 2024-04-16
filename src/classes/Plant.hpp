#ifndef PLANT_HPP
#define PLANT_HPP

#include "Items.hpp"

using namespace std;

class Plant : public Items
{
protected:
    int durationToHarvest;
    int age;

public:
    Plant(int id, string kodeHuruf, string nama, int price, int durationToHarvest);
    virtual ~Plant();

    void setAge(int age);
    int getDurationToHarvest();
    virtual void panen();
    bool isSiapPanen();
    virtual string getType() = 0;
};

#endif