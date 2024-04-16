#ifndef MEMBELI_HPP
#define MEMBELI_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class Membeli : public Commands
{
public:
    Membeli();
    ~Membeli();
    void run(Main &) override;
};

#endif