#include "Bangunan.hpp"

Bangunan::Bangunan(int id, string kodeHuruf, string nama, int price, vector<pair<string, int>> material) : Items(id, kodeHuruf, nama, price)
{
    this->material = material;
}

Bangunan::~Bangunan() {}

vector<pair<string, int>> Bangunan::getMaterial()
{
    return this->material;
}