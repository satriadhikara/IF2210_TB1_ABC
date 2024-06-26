#ifndef MAIN_HPP
#define MAIN_HPP

#include "ConfigController.hpp"
#include "./commands/Commands.hpp"
#include "Plant.hpp"
#include "Animal.hpp"
#include "Product.hpp"
#include "Pemain.hpp"
#include "Bangunan.hpp"
#include "Menu.hpp"
#include "Toko.hpp"
#include <map>
#include <vector>
#include <istream>
using namespace std;

class Main
{
private:
    ConfigController config;
    map<string, Commands *> commands;
    vector<Plant *> plantData;
    vector<Animal *> animalData;
    vector<Product> productData;
    vector<Pemain *> *pemain;
    vector<Bangunan> bangunanData;
    Toko *toko;

    Menu menuController;

    int guldenWin;
    int weightWin;
    int currentPemain;
    bool isRunning;

public:
    Main();
    ~Main();

    bool getIsRunning();
    bool isGameOver();
    int getUrutanPemain();
    int getBanyakPemain();
    void setUrutanPemain(int);
    void runCommand(string);
    Pemain *getCurrentPemain();
    vector<Pemain *> *getPemain();
    vector<Plant *> *getPlantData();
    vector<Animal *> *getAnimalData();
    vector<Product> *getProductData();
    vector<Bangunan> *getBangunanData();
    Toko *getToko();

    friend istream &operator>>(istream &in, Main &main);
};

#endif