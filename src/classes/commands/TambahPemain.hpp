#ifndef TAMBAH_PEMAIN_HPP
#define TAMBAH_PEMAIN_HPP

#include "Commands.hpp"
#include "../Main.hpp"

class TambahPemain : public Commands
{
public:
    TambahPemain();
    ~TambahPemain();
    void run(Main& ) override;
};

#endif