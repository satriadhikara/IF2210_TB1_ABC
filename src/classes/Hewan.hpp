#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "Tipe_Properti.hpp"
using namespace std;

class Hewan : public Tipe_Properti
{
protected:
    static int jumlahHewan;
    int berat_panen;

public:
    Hewan();
    Hewan(int id, string kode, string nama, string tipe, int berat_panen, int harga);
    Hewan(const Hewan &hewan);
    ~Hewan();

    void setBeratPanen(int berat_panen);
    int getBeratPanen();
    static int getJumlahHewan();
};

#endif