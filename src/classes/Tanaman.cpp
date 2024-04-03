#include <iostream>
#include "Tanaman.hpp"

Tanaman::Tanaman() : Tipe_Properti(){}

Tanaman::Tanaman(int id, string kode, string nama, string tipe, int durasi_tumbuh, int harga) :  Tipe_Properti(id, kode, nama, tipe, harga){
    this->durasi_tumbuh = durasi_tumbuh;
}

Tanaman::Tanaman(const Tanaman &tanaman) :  Tipe_Properti(tanaman.id, tanaman.kode, tanaman.nama, tanaman.tipe, tanaman.harga) {
    this->durasi_tumbuh = tanaman.durasi_tumbuh;
}

Tanaman::~Tanaman(){}

void Tanaman::setDurasiPanen(int durasi_panen){
    this->durasi_panen = durasi_panen;
}

int Tanaman::getDurasiPanen(){
    return this->durasi_panen;
}

static int Tanaman::getJumlahTanaman(){
    return this->jumlahTanaman;
}