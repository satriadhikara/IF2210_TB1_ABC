#ifndef MAKAN_HPP
#define MAKAN_HPP

#include "Commands.hpp"

class Makan : public Commands
{
public:
    void run() override;
};

#endif