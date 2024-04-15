#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Pemain.hpp"
#include <vector>

using namespace std;

class Walikota : public Pemain
{
public:
    Walikota(string username, int gulden, int beratbadan);
    ~Walikota();

    string getRole() override;

    int tagihPajak(Pemain *&);
    void bangunBangunan();
    void tambahPemain();
};

#endif