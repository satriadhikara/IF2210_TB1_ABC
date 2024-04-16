#include "Menjual.hpp"

#include <iostream>
#include <sstream>

Menjual::Menjual()
{
}

Menjual::~Menjual()
{
}

void Menjual::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    Toko *toko = main.getToko(); 
    pemain->menjual(pemain, toko);   
}