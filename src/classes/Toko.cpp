#include "Toko.hpp"
#include <iostream>
#include "../utils/Exception.hpp"

using namespace std;

Toko::Toko(vector<Product> &product, vector<Animal *> &animal, vector<Plant *> &plant, vector<Bangunan> &bangunan)
{
    for (auto &i : product)
    {
        items.push_back(make_pair(&i, 0));
    }

    for (auto &i : animal)
    {
        items.push_back(make_pair(i, -1));
    }

    for (auto &i : plant)
    {
        items.push_back(make_pair(i, -1));
    }

    for (auto &i : bangunan)
    {
        items.push_back(make_pair(&i, 0));
    }
}

Toko::~Toko()
{
}

void Toko::showItems()
{
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    int i = 1;
    for (auto &item : items)
    {
        if (item.second == -1)
        {
            cout << i << ". " << item.first->getNama() << " - " << item.first->getPrice() << endl;
        }
        else
        {
            cout << i << ". " << item.first->getNama() << " - " << item.first->getPrice() << " (" << item.second << ")" << endl;
        }
        i++;
    }
}

string Toko::dibeli(int index, int banyak)
{
    index -= 1;
    if (items[index].second == -1)
    {
        return items[index].first->getKodeHuruf();
    }
    else if (items[index].second > 0)
    {
        if (items[index].second >= banyak)
        {
            items[index].second -= banyak;
            return items[index].first->getKodeHuruf();
        }
        else
        {
            throw "Barang tidak cukup";
        }
    }
    else
    {
        throw BeliException();
    }
}

void Toko::menjual(string kodeHuruf)
{
    for (auto &i : items)
    {
        if (i.first->getKodeHuruf() == kodeHuruf)
        {
            i.second++;
            return;
        }
    }
    throw JualException();
}

string Toko::getNamaItem(int index)
{
    return items[index - 1].first->getNama();
}

Items *Toko::getItem(string kodeHuruf)
{
    for (auto &i : items)
    {
        if (i.first->getKodeHuruf() == kodeHuruf)
        {
            return i.first;
        }
    }
    throw "Barang tidak ditemukan";
}