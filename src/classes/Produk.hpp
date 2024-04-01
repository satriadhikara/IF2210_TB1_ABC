#ifndef PRODUK_HPP
#define PRODUK_HPP

#include "../utils/includes.hpp"
#include "Tipe_Properti.hpp"
using namespace std;

class Produk : public Tipe_Properti
{
private:
    static int jumlahProduk;
    int berat_tambahan;
    string origin;

public:
    Produk();
    Produk(int id, string kode, string nama, string tipe, int berat_tambahan, int harga, string origin);
    ~Produk();
};

#endif