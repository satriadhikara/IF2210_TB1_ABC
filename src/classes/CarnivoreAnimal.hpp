#ifndef CARVIVORE_ANIMAL_HPP
#define CARVIVORE_ANIMAL_HPP

#include "Animal.hpp"

class CarnivoreAnimal : public Animal
{
public:
    CarnivoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest);
    ~CarnivoreAnimal();

    void panen(Matrix<string> &) override;
    string getType() override;
};

#endif