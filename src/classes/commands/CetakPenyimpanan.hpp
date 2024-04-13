#ifndef CETAK_PENYIMPANAN_HPP
#define CETAK_PENYIMPANAN_HPP

#include "Commands.hpp"
#include "../Main.hpp"

using namespace std;

class CetakPenyimpanan : public Commands
{
public:
    CetakPenyimpanan();
    ~CetakPenyimpanan();
    void run(Main &) override;
};

#endif