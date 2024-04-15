#ifndef PETANI_HPP
#define PETANI_HPP

#include "Pemain.hpp"
#include "Ladang.hpp"
#include "Plant.hpp"

using namespace std;

class Petani : public Pemain
{
private:
    Ladang *ladang;

public:
    Petani(string username, int gulden, int beratbadan);
    ~Petani();

    void cetakLadang();
    void tanam();
    void panen();
};

#endif