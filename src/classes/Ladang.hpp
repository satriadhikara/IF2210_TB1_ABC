#ifndef LADANG_HPP
#define LADANG_HPP

#include "Matrix.hpp"
#include "Pcolor.hpp"
#include "Plant.hpp"

class Ladang : public Matrix<Plant *>
{
public:
    Ladang(int row, int col);
    ~Ladang();
    void setPlant(int row, int col, Plant *plant);
    bool isFull();
    friend ostream &operator<<(ostream &os, Ladang &l);
};

#endif