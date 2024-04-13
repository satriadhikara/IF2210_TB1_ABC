#ifndef MENU_HPP
#define MENU_HPP

#include "Pemain.hpp"
#include <vector>

using namespace std;

class Menu
{
private:
public:
    Menu();
    ~Menu();

    void showMenuAwal();

    void opsiBacaState(vector<Pemain *> &);
};

#endif