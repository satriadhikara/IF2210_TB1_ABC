#ifndef CETAK_PETERNAKAN_HPP
#define CETAK_PETERNAKAN_HPP

#include "Commands.hpp"
#include "../Main.hpp"

using namespace std;

class CetakPeternakan : public Commands
{
public:
    CetakPeternakan();
    ~CetakPeternakan();
    void run(Main&) override;
};

#endif