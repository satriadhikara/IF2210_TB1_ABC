#ifndef TANAM_HPP
#define TANAM_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Tanam : public Commands
{
public:
    Tanam();
    ~Tanam();
    void run(Main &) override;
};

#endif