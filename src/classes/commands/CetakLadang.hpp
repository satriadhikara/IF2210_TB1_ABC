#ifndef CETAK_LADANG_HPP
#define CETAK_LADANG_HPP

#include "Commands.hpp"

using namespace std;

class CetakLadang : public Commands
{
public:
    void run() override;
};

#endif