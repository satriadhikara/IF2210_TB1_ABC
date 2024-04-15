#include "CetakLadang.hpp"
#include "../Petani.hpp"
#include "../../utils/Exception.hpp"

CetakLadang::CetakLadang() {}

CetakLadang::~CetakLadang() {}

void CetakLadang::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    Petani *petani = dynamic_cast<Petani *>(pemain);

    if (petani)
    {
        petani->cetakLadang();
    }
    else
    {
        throw CetakLadangException();
    }
}