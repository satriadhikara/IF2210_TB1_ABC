#ifndef SIMPAN_HPP
#define SIMPAN_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Simpan : public Commands
{
public:
    Simpan();
    ~Simpan();
    void run(Main &) override;
};

#endif