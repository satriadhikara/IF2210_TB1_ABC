#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Pemain.hpp"

using namespace std;

class Peternak : public Pemain
{
private:
    Matrix<string> *peternakan;

public:
    Peternak(string username, int gulden, int beratbadan);
    ~Peternak();

    void cetakPeternakan();
    void ternak();
    void kasihMakan();
    void panen();
};

#endif