#ifndef PROPERTI_HPP
#define PROPERTI_HPP

#include "../utils/includes.hpp"
using namespace std;

class Properti
{
protected:
    int id;
    string kode;
    string nama;
    string tipe;
    int harga;

public:
    Properti();
    Properti(int id, string kode, string nama, string tipe, int harga);
    virtual ~Properti();
    void setId(int id);
    int getId();
    void setKode(string kode);
    string getKode();
    void setNama(string nama);
    string getNama();
    void setTipe(string tipe);
    string getTipe();
    void setHarga(int harga);
    int getHarga();
};

#endif