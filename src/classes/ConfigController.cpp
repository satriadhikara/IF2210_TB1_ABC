#include "ConfigController.hpp"
#include <fstream>
#include <iostream>
#include "String.hpp"
#include "HerbivoreAnimal.hpp"
#include "OmnivoreAnimal.hpp"
#include "CarnivoreAnimal.hpp"

using namespace std;

ConfigController::ConfigController() {}

ConfigController::~ConfigController() {}

void ConfigController::loadConfig(vector<Plant *> &plant, vector<Animal *> &animal, vector<Product> &product, vector<Bangunan> &bangunan)
{
    // // Load animal
    // ifstream file("./configs/animal.txt");
    // if (file.is_open())
    // {
    //     string line;
    //     while (getline(file, line))
    //     {
    //         vector<string> tokens = String::split(line, ' ');
    //         int id;
    //         string kode_huruf;
    //         string name;
    //         string type;
    //         int duration_to_harvest;
    //         int price;
    //         int i = 0;
    //         for (const string &token : tokens)
    //         {
    //             if (i == 0)
    //             {
    //                 id = stoi(token);
    //             }
    //             else if (i == 1)
    //             {
    //                 kode_huruf = token;
    //             }
    //             else if (i == 2)
    //             {
    //                 name = token;
    //             }
    //             else if (i == 3)
    //             {
    //                 type = token;
    //             }
    //             else if (i == 4)
    //             {
    //                 duration_to_harvest = stoi(token);
    //             }
    //             else if (i == 5)
    //             {
    //                 price = stoi(token);
    //             }
    //             i++;
    //         }

    //         if (type == "HERBIVORE")
    //         {
    //             animal.push_back(new HerbivoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
    //         }
    //         else if (type == "OMNIVORE")
    //         {
    //             animal.push_back(new OmniVoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
    //         }
    //         else if (type == "CARNIVORE")
    //         {
    //             animal.push_back(new CarnivoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
    //         }
    //     }
    //     file.close();

    //     // // print all the animals
    //     // for (Animal *a : animal)
    //     // {
    //     //     cout << a->getNama() << endl;
    //     // }
}
// else
// {
//     throw "File not found";
// }
