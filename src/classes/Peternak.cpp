#include "Peternak.hpp"

#include <iostream>

Peternak::Peternak(string username, int gulden, int beratbadan) : Pemain(username, gulden, beratbadan)
{
    this->peternakan = new Matrix<string>(10, 10);
}

Peternak::~Peternak()
{
    delete this->peternakan;
}

void Peternak::cetakPeternakan()
{
    cout << this->peternakan;
}

void Peternak::ternak()
{
    // TODO
}

void Peternak::kasihMakan()
{
    // TODO
}

void Peternak::panen()
{
    // TODO
}

string Peternak::getRole()
{
    return "Peternak";
}