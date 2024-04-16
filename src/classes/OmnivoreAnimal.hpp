#ifndef OMNIVORE_ANIMAL_HPP
#define OMNIVORE_ANIMAL_HPP

#include "Animal.hpp"

class OmnivoreAnimal : public Animal
{
public:
    OmnivoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest);
    ~OmnivoreAnimal();

    void panen(Matrix<string> &) override;
    string getType() override;
};

#endif