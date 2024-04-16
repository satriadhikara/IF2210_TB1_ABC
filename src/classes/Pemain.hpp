#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <string>
#include <map>
#include "Matrix.hpp"
#include "Toko.hpp"
#include "Product.hpp"

class Pemain
{
protected:
    Matrix<string> *penyimpanan;

    string username;
    int gulden;
    int beratbadan;

public:
    Pemain(string username, int gulden, int beratbadan);
    virtual ~Pemain();

    string getUsername();
    void setGulden(int gulden);
    int getGulden();
    void setBeratBadan(int beratbadan);
    int getBeratBadan();
    void tambahPenyimpanan(string kode);
    Matrix<string> *getPenyimpanan();
    void cetakPenyimpanan();

    void makan(const vector<Product> &product, int row, int col);

    virtual void membeli(Toko *toko, int index, int banyak);
    virtual void menjual();
    virtual string getRole() = 0;
};

#endif