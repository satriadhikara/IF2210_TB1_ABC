#include "ConfigController.hpp"
#include <fstream>
#include <iostream>
#include "String.hpp"
#include "HerbivoreAnimal.hpp"
#include "OmnivoreAnimal.hpp"
#include "CarnivoreAnimal.hpp"
#include "MaterialPlant.hpp"
#include "FruitPlant.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "Walikota.hpp"
#include "Peternakan.hpp"
#include "Ladang.hpp"

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
                animal.push_back(new OmnivoreAnimal(id, kode_huruf, name, price, duration_to_harvest));
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
            if (type == "MATERIAL_PLANT")
            {
                plant.push_back(new MaterialPlant(id, kode_huruf, name, price, duration_to_harvest));
            }
            else if (type == "FRUIT_PLANT")
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

void ConfigController::loadState(vector<Pemain *> &pemain, const string &filename, vector<Plant *> &plantData, vector<Animal *> &animalData, vector<Product> &productData, vector<Bangunan> &bangunanData)
{
    ifstream file("./configs/state.txt");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        int n = stoi(line);
        for (int i = 0; i < n; i++)
        {
            // contructor
            getline(file, line);
            vector<string> tokens = String::split(line, ' ');
            string username = tokens[0];
            string role = tokens[1];
            int gulden = stoi(tokens[2]);
            int beratbadan = stoi(tokens[3]);

            if (role == "Peternak")
            {
                pemain.push_back(new Peternak(username, gulden, beratbadan));
            }
            else if (role == "Petani")
            {
                pemain.push_back(new Petani(username, gulden, beratbadan));
            }
            else if (role == "Walikota")
            {
                pemain.push_back(new Walikota(username, gulden, beratbadan));
            }
            getline(file, line);
            int penyimpananRow = stoi(line);
            for (int j = 0; j < penyimpananRow; j++)
            {
                getline(file, line);
                for (Plant *p : plantData)
                {
                    if (p->getNama() == line)
                    {
                        pemain[i]->tambahPenyimpanan(p->getKodeHuruf());
                    }
                }
                for (Animal *a : animalData)
                {
                    if (a->getNama() == line)
                    {
                        pemain[i]->tambahPenyimpanan(a->getKodeHuruf());
                    }
                }
                for (Product p : productData)
                {
                    if (p.getNama() == line)
                    {
                        pemain[i]->tambahPenyimpanan(p.getKodeHuruf());
                    }
                }
                for (Bangunan b : bangunanData)
                {
                    if (b.getNama() == line)
                    {
                        pemain[i]->tambahPenyimpanan(b.getKodeHuruf());
                    }
                }
            }
            if (role == "Peternak")
            {
                getline(file, line);
                Peternak *peternak = dynamic_cast<Peternak *>(pemain[i]);
                Peternakan *peternakan = new Peternakan(10, 10);
                int peternakanRow = stoi(line);
                for (int j = 0; j < peternakanRow; j++)
                {
                    getline(file, line);
                    tokens = String::split(line, ' ');
                    string slot = tokens[0];
                    string kodeHewan = tokens[1];
                    int weigth = stoi(tokens[2]);
                    // cout << slot << " " << kodeHewan << " " << weigth << endl;
                    Animal *temp;
                    for (Animal *a : animalData)
                    {
                        if (a->getNama() == kodeHewan)
                        {
                            if (a->getType() == "Carnivore")
                            {
                                temp = new CarnivoreAnimal(a->getId(), a->getKodeHuruf(), a->getNama(), a->getPrice(), a->getWeightToHarvest());
                                temp->setWeight(weigth);
                            }
                            else if (a->getType() == "Herbivore")
                            {
                                temp = new HerbivoreAnimal(a->getId(), a->getKodeHuruf(), a->getNama(), a->getPrice(), a->getWeightToHarvest());
                                temp->setWeight(weigth);
                            }
                            else if (a->getType() == "Omnivore")
                            {
                                temp = new OmnivoreAnimal(a->getId(), a->getKodeHuruf(), a->getNama(), a->getPrice(), a->getWeightToHarvest());
                                temp->setWeight(weigth);
                            }
                        }
                    }

                    int baris, kolom;

                    size_t numPos = slot.find_first_of("0123456789");
                    if (numPos == std::string::npos)
                    {
                        throw "Invalid slot format!";
                    }

                    kolom = 0;
                    for (size_t i = 0; i < numPos; ++i)
                    {
                        kolom = kolom * 26 + (toupper(slot[i]) - 'A' + 1);
                    }
                    --kolom;

                    baris = stoi(slot.substr(numPos)) - 1;

                    peternakan->setAnimal(baris, kolom, temp);
                    // cout << baris << " " << kolom << endl;

                    // cout << temp->getNama() << endl;
                    // cout << temp->getKodeHuruf() << endl;
                }
                peternak->setPeternakan(peternakan);
            }
            else if (role == "Petani")
            {
                getline(file, line);
                Petani *petani = dynamic_cast<Petani *>(pemain[i]);
                Ladang *ladang = new Ladang(10, 10);
                int petakRow = stoi(line);
                for (int j = 0; j < petakRow; j++)
                {
                    getline(file, line);
                    tokens = String::split(line, ' ');
                    string slot = tokens[0];
                    string kodeTanaman = tokens[1];
                    int age = stoi(tokens[2]);
                    Plant *temp;
                    for (Plant *p : plantData)
                    {
                        if (p->getNama() == kodeTanaman)
                        {
                            if (p->getType() == "MATERIAL_PLANT")
                            {
                                temp = new MaterialPlant(p->getId(), p->getKodeHuruf(), p->getNama(), p->getPrice(), p->getDurationToHarvest());
                            }
                            else if (p->getType() == "FRUIT_PLANT")
                            {
                                temp = new FruitPlant(p->getId(), p->getKodeHuruf(), p->getNama(), p->getPrice(), p->getDurationToHarvest());
                            }
                        }
                        temp->setAge(age);
                    }

                    int baris, kolom;

                    size_t numPos = slot.find_first_of("0123456789");
                    if (numPos == std::string::npos)
                    {
                        throw "Invalid slot format!";
                    }

                    kolom = 0;
                    for (size_t i = 0; i < numPos; ++i)
                    {
                        kolom = kolom * 26 + (toupper(slot[i]) - 'A' + 1);
                    }
                    --kolom;

                    baris = stoi(slot.substr(numPos)) - 1;

                    ladang->setPlant(baris, kolom, temp);
                }
                petani->setLadang(ladang);
            }
        }
        file.close();
    }
    else
    {
        throw "File state.txt not found!";
    }
}

void ConfigController::saveState(vector<Pemain *> &pemain, string lokasi, vector<Plant *> &plantData, vector<Animal *> &animalData, vector<Product> &productData, vector<Bangunan> &bangunanData)
{
    ofstream file(lokasi);
    if (file.is_open())
    {
        file << pemain.size() << endl;
        for (Pemain *p : pemain)
        {
            file << p->getUsername() << " " << p->getRole() << " " << p->getGulden() << " " << p->getBeratBadan() << endl;
            file << p->getPenyimpanan()->getRow() << endl;
            for (int i = 0; i < p->getPenyimpanan()->getRow(); i++)
            {
                for (int j = 0; j < p->getPenyimpanan()->getCol(); j++)
                {
                    if (p->getPenyimpanan()->getElmt(i, j) != "")
                    {
                        for (Plant *plant : plantData)
                        {
                            if (plant->getKodeHuruf() == p->getPenyimpanan()->getElmt(i, j))
                            {
                                file << plant->getNama() << endl;
                                break;
                            }
                        }
                        for (Animal *animal : animalData)
                        {
                            if (animal->getKodeHuruf() == p->getPenyimpanan()->getElmt(i, j))
                            {
                                file << animal->getNama() << endl;
                                break;
                            }
                        }
                        for (Product product : productData)
                        {
                            if (product.getKodeHuruf() == p->getPenyimpanan()->getElmt(i, j))
                            {
                                file << product.getNama() << endl;
                                break;
                            }
                        }
                        for (Bangunan bangunan : bangunanData)
                        {
                            if (bangunan.getKodeHuruf() == p->getPenyimpanan()->getElmt(i, j))
                            {
                                file << bangunan.getNama() << endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        throw "File not found!";
    }
}

void ConfigController::loadMisc(int &guldenWin, int &weightWin)
{
    ifstream file("./configs/misc.txt");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        guldenWin = stoi(line);
        getline(file, line);
        weightWin = stoi(line);
        file.close();
    }
    else
    {
        throw "File misc.txt not found!";

    }
}