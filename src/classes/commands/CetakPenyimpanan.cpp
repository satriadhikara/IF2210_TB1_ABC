#include "CetakPenyimpanan.hpp"
#include "../../utils/Exception.hpp"

CetakPenyimpanan::CetakPenyimpanan()
{
}

CetakPenyimpanan::~CetakPenyimpanan()
{
}

void CetakPenyimpanan::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    if (pemain)
    {
        pemain->cetakPenyimpanan();
    }
    else
    {
        throw CetakPenyimpananException();
    }
}