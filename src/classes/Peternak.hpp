#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Pemain.hpp"
#include "Peternakan.hpp"

using namespace std;

class Peternak : public Pemain
{
private:
    Peternakan *peternakan;

public:
    Peternak(string username, int gulden, int beratbadan);
    ~Peternak();

    string getRole() override;

    void cetakPeternakan();
    void ternak();
    void kasihMakan();
    void panen();
};

#endif