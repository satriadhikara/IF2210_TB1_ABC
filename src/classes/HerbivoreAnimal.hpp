#ifndef HERBIVORE_ANIMAL_HPP
#define HERBIVORE_ANIMAL_HPP

#include "Animal.hpp"
class HerbivoreAnimal : public Animal
{
public:
    HerbivoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest);
    ~HerbivoreAnimal();

    void panen(Matrix<string> &) override;
};

#endif