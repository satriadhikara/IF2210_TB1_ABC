#ifndef RESEP_HPP
#define RESEP_HPP

#include "Properti.hpp"
class Resep : public Properti
{
private:
    vector<pair<string, int>> bahan;

public:
    Resep();
    Resep(int id, string kode, string nama, string tipe, int harga, vector<pair<string, int>> bahan);
    ~Resep();
    // vector<pair<string, int>> getBahan();
    // void setBahan(vector<pair<string, int>> bahan);
    // void addBahan(string nama, int jumlah);
    // void removeBahan(string nama);
    // void showBahan();
    // void show();
};

#endif