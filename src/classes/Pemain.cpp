#include "Pemain.hpp"
#include <iostream>

Pemain::Pemain(string username, int gulden, int beratbadan)
{
    this->username = username;
    this->gulden = gulden;
    this->beratbadan = beratbadan;
    this->penyimpanan = new Matrix<string>(10, 10);
}

Pemain::~Pemain()
{
    delete this->penyimpanan;
}

string Pemain::getUsername()
{
    return this->username;
}

void Pemain::setGulden(int gulden)
{
    this->gulden = gulden;
}

int Pemain::getGulden()
{
    return this->gulden;
}

void Pemain::setBeratBadan(int beratbadan)
{
    this->beratbadan = beratbadan;
}

int Pemain::getBeratBadan()
{
    return this->beratbadan;
}

void Pemain::tambahPenyimpanan(string kode)
{
    // for (int i = 0; i < this->penyimpanan->getRow(); i++)
    // {
    //     for (int j = 0; j < this->penyimpanan->getCol(); j++)
    //     {
    //         if (this->penyimpanan->getElmt(i, j) == "")
    //         {
    //             this->penyimpanan->setElmt(i, j, kode);
    //             return;
    //         }
    //     }
    // }
}

void Pemain::cetakPenyimpanan()
{
    // cout << *this->penyimpanan;
}

void Pemain::makan()
{
    // TODO
}

void Pemain::membeli()
{
    // TODO
}

void Pemain::menjual()
{
    // TODO
}