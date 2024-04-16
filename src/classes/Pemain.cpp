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
    for (int i = 0; i < this->penyimpanan->getRow(); i++)
    {
        for (int j = 0; j < this->penyimpanan->getCol(); j++)
        {
            if (this->penyimpanan->getElmt(i, j) == "")
            {
                this->penyimpanan->setElmt(i, j, kode);
                return;
            }
        }
    }
}

Matrix<string> *Pemain::getPenyimpanan()
{
    return this->penyimpanan;
}

void Pemain::cetakPenyimpanan()
{
    cout << *this->penyimpanan;
}

void Pemain::makan(const vector<Product> &product, int row, int col)
{
    if (this->penyimpanan->getElmt(row, col) == "")
    {
        throw "Kamu mengambil harapan kosong dari penyimpanan.";
    }
    else
    {
        for (Product p : product)
        {
            if (p.getKodeHuruf() == this->penyimpanan->getElmt(row, col))
            {
                this->beratbadan += p.getAddedWeight();
                this->penyimpanan->setElmt(row, col, "");
                cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                cout << "Alhasil, berat badan kamu naik menjadi " << this->beratbadan << endl;
                return;
            }
        }
        throw "Apa yang kamu lakukan?! Kamu mencoba untuk memakan itu?!!\nSilahkan masukan slot yang berisi makanan.";
    }
}

void Pemain::membeli(Toko *toko, int index, int banyak)
{
    string kode = toko->dibeli(index, banyak);
    for (int i = 0; i < banyak; i++)
    {
        this->tambahPenyimpanan(kode);
    }

    cout << kode << " berhasil disimpan di penyimpanan!" << endl;
}

void Pemain::menjual()
{
    // TODO
}