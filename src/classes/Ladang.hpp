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
    void listTumbuhan(); // print list tumbuhan yang ada di ladang dan tidak mengulang jika sudah di print
    void listSiapPanen(); // print list tumbuhan yang siap panen dengan jumlah masing masing tumbuhan yang siap dipanen
    friend ostream &operator<<(ostream &os, Ladang &l);
};

#endif