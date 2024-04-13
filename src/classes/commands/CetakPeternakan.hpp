#ifndef CETAK_PETERNAKAN_HPP
#define CETAK_PETERNAKAN_HPP

#include "Commands.hpp"

using namespace std;

class CetakPeternakan : public Commands
{
public:
    void run() override;
};

#endif