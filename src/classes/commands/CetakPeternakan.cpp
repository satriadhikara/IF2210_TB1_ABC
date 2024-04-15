#include "CetakPeternakan.hpp"
#include "../Peternak.hpp"

CetakPeternakan::CetakPeternakan(){

}

CetakPeternakan::~CetakPeternakan(){

}

void CetakPeternakan::run(Main &main){
    Pemain *pemain = main.getCurrentPemain();
    Peternak *peternak = dynamic_cast<Peternak *>(pemain);

    if (peternak)
    {
        peternak->cetakPeternakan();
    }
    else
    {
        throw "Pemain bukan peternak";
    }
}