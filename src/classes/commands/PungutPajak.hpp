#ifndef PUNGUT_PAJAK_HPP
#define PUNGUT_PAJAK_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class PungutPajak : public Commands
{
public:
    PungutPajak();
    ~PungutPajak();
    void run(Main &) override;
};

#endif