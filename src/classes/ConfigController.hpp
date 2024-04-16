#ifndef CONFIG_CONTROLLER_HPP
#define CONFIG_CONTROLLER_HPP

#include "Plant.hpp"
#include "Animal.hpp"
#include "Product.hpp"
#include "Bangunan.hpp"
#include "Pemain.hpp"

using namespace std;

class ConfigController
{
private:
public:
    ConfigController();
    ~ConfigController();

    void loadConfig(vector<Plant *> &, vector<Animal *> &, vector<Product> &, vector<Bangunan> &);
    void loadState(vector<Pemain *> &pemain, const string &filename, vector<Plant *> &plantData, vector<Animal *> &animalData, vector<Product> &productData, vector<Bangunan> &bangunanData);
    void saveState();
    void loadMisc(int &guldenWin, int &weightWin);
};

#endif