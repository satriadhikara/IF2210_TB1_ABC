#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Items.hpp"
#include "Matrix.hpp"

class Animal : public Items
{
protected:
    int weightToHarvest;
    int weight;

public:
    Animal(int id, string kodeHuruf, string nama, int price, int weightToHarvest);
    virtual ~Animal();

    int getWeightToHarvest();
    virtual void panen(Matrix<string> &) = 0;
    bool isSiapPanen();
    virtual string getType() = 0;
    void setBerat(int berat);
};

#endif