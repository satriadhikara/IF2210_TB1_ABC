#ifndef MENU_HPP
#define MENU_HPP

#include "Pemain.hpp"
#include "Plant.hpp"
#include "Animal.hpp"
#include "Product.hpp"
#include <vector>

using namespace std;

class Menu
{
private:
public:
    Menu();
    ~Menu();

    void showMenuAwal();

    void opsiBacaState(vector<Pemain *> &, vector<Plant *> &, vector<Animal *> &, vector<Product> &, vector<Bangunan> &);
};

#endif