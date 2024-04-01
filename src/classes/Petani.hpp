#ifndef PETANI_HPP
#define PETANI_HPP

#include "Pemain.hpp"
#include "Tanaman.hpp"
using namespace std;

class Petani : public Pemain
{
private:
    vector<Tanaman> tanaman;

public:
    Petani();
    Petani(string nama, int uang, int bb);
    ~Petani();

    void menanam(const Tanaman &);
    Tanaman getTanaman(int id);
    void memanen();
};

#endif