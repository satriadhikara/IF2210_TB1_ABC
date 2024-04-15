#include "Walikota.hpp"

Walikota::Walikota(string username, int gulden, int beratbadan) : Pemain(username, gulden, beratbadan)
{
}

Walikota::~Walikota()
{
}

int Walikota::tagihPajak(Pemain *&pemain)
{
    int kkp;
    if (pemain->getRole() == "Petani")
    {
        kkp = pemain->getGulden() - 13;
    }
    else if (pemain->getRole() == "Peternak")
    {
        kkp = pemain->getGulden() - 11;
    }

    int hasilTagihan;

    if (kkp > 500)
    {
        hasilTagihan = kkp - (kkp * 0.35);
    }
    else if (kkp > 50)
    {
        hasilTagihan = kkp - (kkp * 0.3);
    }
    else if (kkp > 25)
    {
        hasilTagihan = kkp - (kkp * 0.25);
    }
    else if (kkp > 6)
    {
        hasilTagihan = kkp - (kkp * 0.15);
    }
    else if (kkp > 0)
    {
        hasilTagihan = kkp - (kkp * 0.05);
    }
    pemain->setGulden(hasilTagihan);
    this->setGulden(hasilTagihan);
    return hasilTagihan;
}

void Walikota::bangunBangunan()
{
    // TODO
}

void Walikota::tambahPemain()
{
    // TODO
}

string Walikota::getRole()
{
    return "Walikota";
}