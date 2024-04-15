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
    friend ostream &operator<<(ostream &os, Ladang &l);
};

#endif