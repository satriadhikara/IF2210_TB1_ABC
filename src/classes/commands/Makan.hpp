#ifndef MAKAN_HPP
#define MAKAN_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Makan : public Commands
{
public:
    Makan();
    ~Makan();
    void run(Main &) override;
};

#endif