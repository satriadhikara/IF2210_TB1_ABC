#include "Ternak.hpp"
#include "../Peternak.hpp"
#include "../../utils/Exception.hpp"

Ternak::Ternak() {}

Ternak::~Ternak() {}

void Ternak::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    Peternak *peternak = dynamic_cast<Peternak *>(pemain);

    if (peternak)
    {
        peternak->ternak(*main.getAnimalData());
    }
    else
    {
        //throw TernakException();
    }
}