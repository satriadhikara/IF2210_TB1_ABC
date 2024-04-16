#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>

using namespace std;

class Items
{
protected:
    int id;
    string kodeHuruf;
    string nama;
    int price;

public:
    Items(int id, string kodeHuruf, string nama, int price);
    Items(const Items &items);
    virtual ~Items();

    int getId();
    string getKodeHuruf();
    string getNama();
    int getPrice();
};

#endif