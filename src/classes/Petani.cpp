#include "Petani.hpp"

#include <iostream>

Petani::Petani(string username, int gulden, int beratbadan) : Pemain(username, gulden, beratbadan)
{
    this->ladang = new Matrix<string>(10, 10);
}

Petani::~Petani()
{
    delete this->ladang;
}

void Petani::cetakLadang()
{
    // cout << *this->ladang;
}

void Petani::tanam()
{
    // TODO
}

void Petani::panen()
{
    // TODO
}