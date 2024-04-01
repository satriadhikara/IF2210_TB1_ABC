#ifndef TIPE_PROPERTI_HPP
#define TIPE_PROPERTI_HPP

#include "Properti.hpp"

class Tipe_Properti : public Properti
{
protected:
    string tipe;

public:
    Tipe_Properti();
    Tipe_Properti(int id, string kode, string nama, string tipe, int harga);
    virtual ~Tipe_Properti();

    void setTipe(string tipe);
    string getTipe();
};

#endif