#ifndef PETANI_HPP
#define PETANI_HPP

#include "Pemain.hpp"

using namespace std;

class Petani : public Pemain
{
private:
    Matrix<string> *ladang;

public:
    Petani(string username, int gulden, int beratbadan);
    ~Petani();

    void cetakLadang();
    void tanam();
    void panen();
};

#endif