#ifndef MEMANEN_HPP
#define MEMANEN_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Memanen : public Commands
{
public:
    void run(Main &) override;
};

#endif