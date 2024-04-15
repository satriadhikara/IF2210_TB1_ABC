#include "TambahPemain.hpp"
#include "../Walikota.hpp"
#include "../../utils/Exception.hpp"

#include <iostream>

TambahPemain::TambahPemain() {}

TambahPemain::~TambahPemain() {}

void TambahPemain::run(Main &main) {
   Pemain *pemain = main.getCurrentPemain();
   Walikota *walikota = dynamic_cast<Walikota *>(pemain);
   if (walikota){
    walikota->tambahPemain(*main.getPemain());
   }
   else
   {
    throw "Test";
   }
}