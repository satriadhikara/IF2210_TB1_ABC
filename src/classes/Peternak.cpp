#include "Peternak.hpp"
#include "CarnivoreAnimal.hpp"
#include "HerbivoreAnimal.hpp"
#include "OmnivoreAnimal.hpp"

#include <iostream>

Peternak::Peternak(string username, int gulden, int beratbadan) : Pemain(username, gulden, beratbadan)
{
    this->peternakan = new Peternakan(10, 10);
}

Peternak::~Peternak()
{
    delete this->peternakan;
}

void Peternak::cetakPeternakan()
{
    cout << *this->peternakan;
}

void Peternak::ternak(const vector<Animal*>& animalData)
{
    if (this->peternakan->isFull()) {
        throw "Peternakan sudah penuh!";
    } else if (!cekInventoryPeternak(animalData)) {
        throw "Tidak ada hewan di penyimpanan!";
    } else {
        string slot;
        cout << "Pilih hewan dari penyimpanan" << endl;
        this->cetakPenyimpanan();

        cout << "Slot: ";
        cin >> slot;

        int baris, kolom;

        size_t numPos = slot.find_first_of("0123456789");
        if (numPos == std::string::npos) {
            throw "Invalid slot format!";
        }

        kolom = 0;
        for (size_t i = 0; i < numPos; ++i) {
            kolom = kolom * 26 + (toupper(slot[i]) - 'A' + 1);
        }
        --kolom;

        baris = stoi(slot.substr(numPos)) - 1;
        
        string kodeHewan = this->penyimpanan->getElmt(baris, kolom);
        if (kodeHewan == "") {
            throw "Slot kosong!";
        } else {
            if (!this->cekHewan(animalData, kodeHewan)) {
                throw "Bukan hewan!";
            } else {
                this->penyimpanan->setElmt(baris, kolom, "");
            }
        }

        int i = 0;
        Animal* hewan = nullptr;
        while (i < animalData.size()) {
            if (animalData[i]->getKodeHuruf() == kodeHewan) {
                if (animalData[i]->getType() == "Carnivore") {
                    hewan = new CarnivoreAnimal(animalData[i]->getId(), animalData[i]->getKodeHuruf(), animalData[i]->getNama(), animalData[i]->getPrice(), animalData[i]->getWeightToHarvest());
                } else if (animalData[i]->getType() == "Herbivore") {
                    hewan = new HerbivoreAnimal(animalData[i]->getId(), animalData[i]->getKodeHuruf(), animalData[i]->getNama(), animalData[i]->getPrice(), animalData[i]->getWeightToHarvest());
                } else if (animalData[i]->getType() == "Omnivore") {
                    hewan = new OmnivoreAnimal(animalData[i]->getId(), animalData[i]->getKodeHuruf(), animalData[i]->getNama(), animalData[i]->getPrice(), animalData[i]->getWeightToHarvest());
                }
            }
            i++;
        }

        string tanahternak;
        cout << "Pilih petak tanah yang akan ditinggali";
        this->cetakPeternakan();
        cout << "Petak tanah: ";
        cin >> tanahternak;

        size_t numPos = tanahternak.find_first_of("0123456789");
        if (numPos == std::string::npos) {
            throw "Invalid tanah format!";
        }

        kolom = 0;
        for (size_t i = 0; i < numPos; ++i) {
            kolom = kolom * 26 + (toupper(tanahternak[i]) - 'A' + 1);
        }
        --kolom;

        baris = stoi(tanahternak.substr(numPos)) - 1;

        this->peternakan->setAnimal(baris, kolom, hewan);

        cout << "Dengan hati-hati, kamu meletakkan seekor " << hewan->getNama() << " di kandang." << endl;
        cout << hewan->getNama() << "Chicken telah menjadi peliharaanmu sekarang!" << endl;
    }
}

void Peternak::kasihMakan()
{
    // TODO
}

void Peternak::panen()
{
    // TODO
}

string Peternak::getRole()
{
    return "Peternak";
}

bool Peternak::cekHewan(const vector<Animal*>& animalData, const string& kodeHuruf)
{
    for (size_t i = 0; i < animalData.size(); ++i) {
        if (animalData[i]->getKodeHuruf() == kodeHuruf) {
            return true;
        }
    }
    return false;
}

bool Peternak::cekInventoryPeternak(const vector<Animal*>& animalData)
{
    for (int i = 0; i < this->penyimpanan->getRow(); i++) {
        for (int j = 0; j < this->penyimpanan->getCol(); j++) {
            for (int k = 0; k < animalData.size(); k++) {
                if (this->penyimpanan->getElmt(i, j) == animalData[k]->getKodeHuruf()) {
                    return true;
                }
            }
        }
    }
    return false;
}