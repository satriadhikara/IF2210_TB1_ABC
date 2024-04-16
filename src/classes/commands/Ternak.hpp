#ifndef TERNAK_HPP
#define TERNAK_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Ternak : public Commands
{
public:
    Ternak();
    ~Ternak();
    void run(Main &) override;
};

#endif