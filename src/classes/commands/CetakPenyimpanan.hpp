#ifndef CETAK_PENYIMPANAN_HPP
#define CETAK_PENYIMPANAN_HPP

#include "Commands.hpp"

using namespace std;

class CetakPenyimpanan : public Commands
{
public:
    void run() override;
};

#endif