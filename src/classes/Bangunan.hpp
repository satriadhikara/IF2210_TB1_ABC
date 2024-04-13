#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "Items.hpp"
#include <vector>

using namespace std;

class Bangunan : public Items
{
private:
    vector<pair<string, int>> material;

public:
    Bangunan(int id, string kodeHuruf, string nama, int price, vector<pair<string, int>> material);
    ~Bangunan();

    vector<pair<string, int>> getMaterial();
};

#endif