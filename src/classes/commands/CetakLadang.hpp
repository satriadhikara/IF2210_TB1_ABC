#ifndef CETAK_LADANG_HPP
#define CETAK_LADANG_HPP

#include "Commands.hpp"
#include "../Main.hpp"

using namespace std;

class CetakLadang : public Commands
{
public:
    CetakLadang();
    ~CetakLadang();
    void run(Main &) override;
};

#endif