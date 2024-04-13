#ifndef CONFIG_CONTROLLER_HPP
#define CONFIG_CONTROLLER_HPP

#include "Plant.hpp"
#include "Animal.hpp"
#include "Product.hpp"
#include "Bangunan.hpp"

using namespace std;

class ConfigController
{
private:
public:
    ConfigController();
    ~ConfigController();

    void loadConfig(vector<Plant *> &, vector<Animal *> &, vector<Product> &, vector<Bangunan> &);
    void loadState();
    void saveState();
};

#endif