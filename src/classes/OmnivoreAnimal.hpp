#ifndef OMNIVORE_ANIMAL_HPP
#define OMNIVORE_ANIMAL_HPP

#include "Animal.hpp"

class OmniVoreAnimal : public Animal
{
public:
    OmniVoreAnimal(int id, string kodeHuruf, string nama, int price, int weightToHarvest);
    ~OmniVoreAnimal();

    void panen(Matrix<string> &) override;
};

#endif