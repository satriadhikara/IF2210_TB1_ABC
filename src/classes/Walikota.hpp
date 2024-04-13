#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Pemain.hpp"

using namespace std;

class Walikota : public Pemain
{
public:
    Walikota(string username, int gulden, int beratbadan);
    ~Walikota();

    void tagihPajak();
    void bangunBangunan();
    void tambahPemain();
};

#endif