#include "ConfigController.hpp"
#include <fstream>
#include <iostream>
#include "String.hpp"
#include "HerbivoreAnimal.hpp"
#include "OmnivoreAnimal.hpp"
#include "CarnivoreAnimal.hpp"
#include "MaterialPlant.hpp"
#include "FruitPlant.hpp"

using namespace std;

ConfigController::ConfigController() {}

ConfigController::~ConfigController() {}

void ConfigController::loadConfig(vector<Plant *> &plant, vector<Animal *> &animal, vector<Product> &product, vector<Bangunan> &bangunan)
{
    // Load animal
    ifstream file("./configs/animal.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = String::split(line, ' ');
            int id;
            string kode_huruf;
            string name;
            string type;
            int duration_to_harvest;
            int price;
            int i = 0;
            for (const string &token : tokens)
            {
                if (i == 0)
                {
                    id = stoi(token);
                }
                else if (i == 1)
                {
                    kode_huruf = token;
                }
                else if (i == 2)
                {
                    name = token;
                }
                else if (i == 3)
                {
                    type = token;
                }
                else if (i == 4)
                {
                    duration_to_harvest = stoi(token);
                }
                else if (i == 5)
                {
                    price = stoi(token);
                }
                i++;
            }

            if (type == "HERBIVORE")
            {
                animal.push_back(new HerbivoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
            }
            else if (type == "OMNIVORE")
            {
                animal.push_back(new OmniVoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
            }
            else if (type == "CARNIVORE")
            {
                animal.push_back(new CarnivoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
            }
        }
        file.close();
        // for (Animal *a : animal)
        // {
        //     cout << a->getNama() << endl;
        // }
    }
    else
    {
        throw "File animal.txt not found!";
    }

    // Load plant
    file.open("./configs/plant.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = String::split(line, ' ');
            int id;
            string kode_huruf;
            string name;
            string type;

            int duration_to_harvest;
            int price;
            int i = 0;
            for (const string &token : tokens)
            {
                if (i == 0)
                {
                    id = stoi(token);
                }
                else if (i == 1)
                {
                    kode_huruf = token;
                }
                else if (i == 2)
                {
                    name = token;
                }
                else if (i == 3)
                {
                    type = token;
                }
                else if (i == 4)
                {
                    duration_to_harvest = stoi(token);
                }
                else if (i == 5)
                {
                    price = stoi(token);
                }
                i++;
            }
            if (type == "MATERIAL")
            {
                plant.push_back(new MaterialPlant(id, kode_huruf, name, price, duration_to_harvest));
            }
            else if (type == "FRUIT")
            {
                plant.push_back(new FruitPlant(id, kode_huruf, name, price, duration_to_harvest));
            }
        }
        file.close();
        // for (Plant *p : plant)
        // {
        //     cout << p->getNama() << endl;
        // }
    }
    else
    {
        throw "File plant.txt not found!";
    }

    // Load product
    file.open("./configs/product.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = String::split(line, ' ');
            // for (string &token : tokens)
            // {
            //     cout << token << endl;
            // }
            int id;
            string kode_huruf;
            string name;
            string type;
            string origin;
            int addedWeight;
            int price;
            int i = 0;
            for (const string &token : tokens)
            {
                if (i == 0)
                {
                    id = stoi(token);
                }
                else if (i == 1)
                {
                    kode_huruf = token;
                }
                else if (i == 2)
                {
                    name = token;
                }
                else if (i == 3)
                {
                    type = token;
                }
                else if (i == 4)
                {
                    origin = token;
                }
                else if (i == 5)
                {
                    addedWeight = stoi(token);
                }
                else if (i == 6)
                {
                    price = stoi(token);
                }
                i++;
            }
            product.push_back(Product(id, kode_huruf, name, type, price, origin, addedWeight));
        }
        file.close();
        // for (Product p : product)
        // {
        //     cout << p.getNama() << endl;
        // }
    }
    else
    {
        throw "File product.txt not found!";
    }

    // Load bangunan
    file.open("./configs/recipe.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = String::split(line, ' ');
            int id;
            string kode_huruf;
            string name;
            int price;
            vector<pair<string, int>> material;
            int i = 0;
            for (const string &token : tokens)
            {
                if (i == 0)
                {
                    id = stoi(token);
                }
                else if (i == 1)
                {
                    kode_huruf = token;
                }
                else if (i == 2)
                {
                    name = token;
                }
                else if (i == 3)
                {
                    price = stoi(token);
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        material.push_back(make_pair(token, 0));
                    }
                    else
                    {
                        material.back().second = stoi(token);
                    }
                }
                i++;
            }
            bangunan.push_back(Bangunan(id, kode_huruf, name, price, material));
        }
        file.close();
        // for (Bangunan b : bangunan)
        // {
        //     cout << b.getNama() << endl;
        // }
    }
    else
    {
        throw "File bangunan.txt not found!";
    }
}
