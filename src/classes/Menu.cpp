#include "Menu.hpp"
#include <iostream>
#include "Walikota.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "ConfigController.hpp"

using namespace std;

Menu::Menu() {}
Menu::~Menu() {}

void Menu::showMenuAwal()
{
    cout << "Selamat datang di pengelolaan kerajaan!" << endl;
    cout << "1. Mulai permainan baru" << endl;
    cout << "2. Muat permainan" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukkan pilihan: ";
}

void Menu::opsiBacaState(vector<Pemain *> &pemain, vector<Plant *> &plantData, vector<Animal *> &animalData, vector<Product> &productData, vector<Bangunan> &bangunanData)

{
    int pilihan;
    cin >> pilihan;
    if (pilihan == 1)
    {
        pemain.push_back(new Walikota("Walikota", 50, 40));
        pemain.push_back(new Peternak("Peternak1", 50, 40));
        pemain.push_back(new Petani("Petani1", 50, 40));
    }
    else if (pilihan == 2)
    {
        ConfigController configController;
        configController.loadState(pemain, "state.txt", plantData, animalData, productData, bangunanData);
    }
    else if (pilihan == 3)
    {
        cout << "Terima kasih telah bermain!" << endl;
    }
    else
    {
        cout << "Pilihan tidak valid." << endl;
    }
}