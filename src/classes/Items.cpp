#include "Items.hpp"

Items::Items(int id, string kodeHuruf, string nama, int price)
{
    this->id = id;
    this->kodeHuruf = kodeHuruf;
    this->nama = nama;
    this->price = price;
}

Items::~Items() {}

int Items::getId()
{
    return this->id;
}

string Items::getKodeHuruf()
{
    return this->kodeHuruf;
}

string Items::getNama()
{
    return this->nama;
}

int Items::getPrice()
{
    return this->price;
}