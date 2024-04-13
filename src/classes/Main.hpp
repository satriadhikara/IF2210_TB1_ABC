#ifndef MAIN_HPP
#define MAIN_HPP

// #include "ConfigController.hpp"
#include "./commands/Commands.hpp"
// #include "Plant.hpp"
// #include "Animal.hpp"
// #include "Product.hpp"
#include "Pemain.hpp"
// #include "Bangunan.hpp"
#include "Menu.hpp"
#include <map>
#include <vector>
#include <istream>
using namespace std;

class Main
{
private:
    // ConfigController config;
    map<string, Commands *> commands;
    // vector<Plant *> plantData;
    // vector<Animal *> animalData;
    // vector<Product> productData;
    vector<Pemain *> *pemain;
    // vector<Bangunan> bangunanData;

    Menu menuController;

    int currentPemain;
    bool isRunning;

public:
    Main();
    ~Main();

    bool getIsRunning();
    int getCurrentPemain();
    int getBanyakPemain();
    void setCurrentPemain(int);
    void runCommand(string);

    friend istream &operator>>(istream &in, Main &main);
};

#endif