#include "Tanam.hpp"
#include "../Petani.hpp"
#include "../../utils/Exception.hpp"

Tanam::Tanam() {}

Tanam::~Tanam() {}

void Tanam::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    Petani *petani = dynamic_cast<Petani *>(pemain);

    if (petani)
    {
        petani->tanam(*main.getPlantData()); 
    }
    else
    {
        //throw TanamException();
    }
}