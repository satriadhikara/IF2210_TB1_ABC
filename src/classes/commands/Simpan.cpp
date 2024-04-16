#include "Simpan.hpp"
#include "../Pemain.hpp"
#include <filesystem>
#include <iostream>
#include <vector>

using namespace std;

Simpan::Simpan() {}

Simpan::~Simpan() {}

void Simpan::run(Main &main)
{
    cout << "Masukkan lokasi berkas state : ";
    string lokasi;
    cin >> lokasi;

    if (std::__fs::filesystem::exists(lokasi))
    {
        ConfigController::saveState(*main.getPemain(), lokasi, *main.getPlantData(), *main.getAnimalData(), *main.getProductData(), *main.getBangunanData());
        cout << "State berhasil disimpan!" << endl;
    }
    else
    {
        throw "Lokasi berkas tidak valid!";
    }
}