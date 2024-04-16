#ifndef TOKO_HPP
#define TOKO_HPP

#include "Items.hpp"
#include "Product.hpp"
#include "Animal.hpp"
#include "Plant.hpp"
#include "Bangunan.hpp"
#include <vector>

using namespace std;

class Toko
{
private:
    vector<pair<Items *, int>> items;

public:
    Toko(vector<Product> &product, vector<Animal *> &animal, vector<Plant *> &plant, vector<Bangunan> &bangunan);
    ~Toko();

    void showItems();

    string dibeli(int index, int banyak);
    void menjual(Items *item, int banyak);
    string getNamaItem(int index);
};

#endif