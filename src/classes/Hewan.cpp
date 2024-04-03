#include "Hewan.hpp"
using namespace std;

Hewan :: Hewan() : Properti(){}

Hewan :: Hewan(int id, string kode, string nama, string tipe, int berat_panen, int harga) : Properti(id, kode, nama,tipe, harga), berat_panen{}

Hewan :: Hewan(const Hewan &hewan)
{
    this->id = hewan.id;
    this->kode = hewan.kode;
    this->nama = hewan.nama;
    this->tipe = hewan.tipe;
    this->berat_panen = berat_panen;
    this->harga = hewan.harga;
}

Hewan :: ~Hewan(){}

void Hewan :: setBeratPanen(int setBeratPanen)
{
    berat_panen = setBeratPanen;
}

int Hewan :: getBeratPanen()
{
    return berat_panen;
}

static int Hewan :: getJumlahHewan()
{
    for (int i = 0;)
}