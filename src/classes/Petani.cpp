#include "Petani.hpp"
#include "MaterialPlant.hpp"
#include "FruitPlant.hpp"

#include <iostream>

Petani::Petani(string username, int gulden, int beratbadan) : Pemain(username, gulden, beratbadan)
{
    this->ladang = new Ladang(10, 10);
}

Petani::~Petani()
{
    delete this->ladang;
}

void Petani::setLadang(Ladang *ladang)
{
    this->ladang = ladang;
}
void Petani::cetakLadang()
{
    cout << *this->ladang;
}

void Petani::tanam(const vector<Plant *> &plantData)
{
    if (this->ladang->isFull())
    {
        throw "Ladang sudah penuh!";
    }
    else if (!cekInventoryPetani(plantData))
    {
        throw "Tidak ada tanaman di penyimpanan!";
    }
    else
    {
        string slot;
        cout << "Pilih tanaman dari penyimpanan" << endl;
        this->cetakPenyimpanan();

        cout << "Slot: ";
        cin >> slot;

        int baris, kolom;

        size_t numPos = slot.find_first_of("0123456789");
        if (numPos == std::string::npos)
        {
            throw "Invalid slot format!";
        }

        kolom = 0;
        for (size_t i = 0; i < numPos; ++i)
        {
            kolom = kolom * 26 + (toupper(slot[i]) - 'A' + 1);
        }
        --kolom;

        baris = stoi(slot.substr(numPos)) - 1;

        string kodeTanaman = this->penyimpanan->getElmt(baris, kolom);
        if (kodeTanaman == "")
        {
            throw "Slot kosong!";
        }
        else
        {
            if (!this->cekTanaman(plantData, kodeTanaman))
            {
                throw "Bukan tanaman!";
            }
            else
            {
                this->penyimpanan->setElmt(baris, kolom, "");
            }
        }

        int i = 0;
        Plant *tanaman = nullptr;
        while (i < plantData.size())
        {
            if (plantData[i]->getKodeHuruf() == kodeTanaman)
            {
                if (plantData[i]->getType() == "Material")
                {
                    tanaman = new MaterialPlant(plantData[i]->getId(), plantData[i]->getKodeHuruf(), plantData[i]->getNama(), plantData[i]->getPrice(), plantData[i]->getDurationToHarvest());
                }
                else if (plantData[i]->getType() == "Fruit")
                {
                    tanaman = new FruitPlant((plantData[i]->getId()), plantData[i]->getKodeHuruf(), plantData[i]->getNama(), plantData[i]->getPrice(), plantData[i]->getDurationToHarvest());
                }
            }
            i++;
        }

        cout << "Kamu memilih " << tanaman->getNama() << "." << endl;

        string tanah;
        cout << "Pilih petak tanah yang akan ditanami" << endl;
        this->cetakLadang();
        cout << "Petak tanah: ";
        cin >> tanah;

        numPos = tanah.find_first_of("0123456789");
        if (numPos == std::string::npos)
        {
            throw "Invalid tanah format!";
        }

        kolom = 0;
        for (size_t i = 0; i < numPos; ++i)
        {
            kolom = kolom * 26 + (toupper(tanah[i]) - 'A' + 1);
        }
        --kolom;

        baris = stoi(tanah.substr(numPos)) - 1;

        this->ladang->setPlant(baris, kolom, tanaman);

        cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl
             << tanaman->getNama() << " berhasil ditanam!" << endl;
    }
}

void Petani::panen()
{
    // TODO
}

string Petani::getRole()
{
    return "Petani";
}

bool Petani::cekTanaman(const vector<Plant *> &plantData, const string &kodeHuruf)
{
    bool found = false;
    for (int i = 0; i < plantData.size(); i++)
    {
        if (plantData[i]->getKodeHuruf() == kodeHuruf)
        {
            found = true;
        }
    }

    return found;
}

bool Petani::cekInventoryPetani(const vector<Plant *> &plantData)
{
    bool found = false;
    for (int i = 0; i < this->penyimpanan->getRow(); i++)
    {
        for (int j = 0; j < this->penyimpanan->getCol(); j++)
        {
            for (int k = 0; k < plantData.size(); k++)
            {
                if (this->penyimpanan->getElmt(i, j) == plantData[k]->getKodeHuruf())
                {
                    found = true;
                }
            }
        }
    }

    return found;
}