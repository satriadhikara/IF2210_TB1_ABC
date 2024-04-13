#ifndef NEXT_HPP
#define NEXT_HPP

#include "Commands.hpp"
#include "../Main.hpp"

using namespace std;

class Next : public Commands
{
public:
    Next();
    ~Next();
    void run(Main &) override;
};

#endif