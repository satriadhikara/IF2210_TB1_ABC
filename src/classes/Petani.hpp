#ifndef PETANI_HPP
#define PETANI_HPP

#include "Pemain.hpp"
#include "Ladang.hpp"
#include "Plant.hpp"
#include <vector>

using namespace std;

class Petani : public Pemain
{
private:
    Ladang *ladang;

public:
    Petani(string username, int gulden, int beratbadan);
    ~Petani();

    string getRole() override;

    void cetakLadang();
    void tanam(const vector<Plant*>& plantData);
    void panen();
    bool cekTanaman(const vector<Plant*>& plantData, const string& kodeHuruf);
    bool cekInventoryPetani(const vector<Plant*>& plantData); 
};

#endif