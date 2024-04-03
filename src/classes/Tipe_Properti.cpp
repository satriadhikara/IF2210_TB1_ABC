#include <iostream>
#include "Tipe_Properti.hpp"

Tipe_Properti::Tipe_Properti() : Properti() {}

Tipe_Properti::Tipe_Properti(int id, string kode, string nama, string tipe, int harga) : Properti(id,kode,nama,tipe,harga){}

Tipe_Properti::~Tipe_Properti(){}

void Tipe_Properti::setTipe(string tipe){
    this->tipe = tipe;
}
string Tipe_Properti::getTipe(){
    return this->tipe;
}