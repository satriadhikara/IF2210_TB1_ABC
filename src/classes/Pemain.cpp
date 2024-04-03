#include "Pemain.hpp"
#include <iostream>

Pemain::Pemain() : uang(50), bb(40) {}

Pemain::Pemain(int uang, int bb) : uang(uang), bb(bb) {}

Pemain::~Pemain() {}

void Pemain::showPenyimpanan() {
    std::cout << "Matriks penyimpanan : " << std::endl;
    //ini masih bingung jujurly
}

void Pemain::setUang(int uang) {
    this->uang = uang;
}

int Pemain::getUang() {
    return uang;
}

void Pemain::setBB(int bb) {
    this->bb = bb;
}

int Pemain::getBB() {
    return bb;
}
