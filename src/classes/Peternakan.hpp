#ifndef PETERNAKAN_HPP
#define PETERNAKAN_HPP

#include "Matrix.hpp"
#include "Pcolor.hpp"
#include "Animal.hpp"

class Peternakan : public Matrix<Animal *>
{
public:
    Peternakan(int row, int col);
    ~Peternakan();
    void setAnimal(int row, int col, Animal *animal);
    bool isFull();
    friend ostream &operator<<(ostream &os, Peternakan &p);
    bool isEmpty();
};

#endif