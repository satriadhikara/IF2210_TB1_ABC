#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Pemain.hpp"
#include "Peternakan.hpp"
#include "Animal.hpp"
#include <vector>

using namespace std;

class Peternak : public Pemain
{
private:
    Peternakan *peternakan;

public:
    Peternak(string username, int gulden, int beratbadan);
    ~Peternak();

    string getRole() override;

    void setPeternakan(Peternakan *peternakan);

    void cetakPeternakan();
    void ternak(const vector<Animal *> &animalData);
    void kasihMakan();
    void panen();
    bool cekHewan(const vector<Animal *> &animalData, const string &kodeHuruf);
    bool cekInventoryPeternak(const vector<Animal *> &animalData);
};

#endif