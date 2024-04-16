#ifndef MENJUAL_HPP
#define MENJUAL_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Menjual : public Commands
{
public:
    Menjual();
    ~Menjual();
    void run(Main &) override;
};

#endif