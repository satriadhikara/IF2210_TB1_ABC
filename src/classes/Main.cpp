#include "Main.hpp"
#include "./commands/Next.hpp"
#include "./commands/CetakPenyimpanan.hpp"
#include "./commands/PungutPajak.hpp"
#include "./commands/CetakLadang.hpp"
#include "./commands/CetakPeternakan.hpp"
#include "./commands/Tanam.hpp"
// #include "./commands/Ternak.hpp"
// #include "./commands/BangunBangunan.hpp"
#include "./commands/Makan.hpp"
// #include "./commands/MemberiPangan.hpp"
// #include "./commands/Membeli.hpp"
// #include "./commands/Menjual.hpp"
// #include "./commands/Memanen.hpp"
// #include "./commands/Muat.hpp"
// #include "./commands/Simpan.hpp"
#include "./commands/TambahPemain.hpp"
#include "../../utils/Exception.hpp"

#include <iostream>

using namespace std;

Main::Main()
{
    try
    {
        config.loadConfig(plantData, animalData, productData, bangunanData);
    }
    catch (const char *msg)
    {
        cerr << "Exception: " << msg << endl;
    }

    isRunning = true;
    currentPemain = 0;

    pemain = new vector<Pemain *>();

    menuController.showMenuAwal();
    menuController.opsiBacaState(*pemain);

    commands["NEXT"] = new Next();
    commands["CETAK_PENYIMPANAN"] = new CetakPenyimpanan();
    commands["PUNGUT_PAJAK"] = new PungutPajak();
    commands["CETAK_LADANG"] = new CetakLadang();
    commands["CETAK_PETERNAKAN"] = new CetakPeternakan();
    commands["TANAM"] = new Tanam();
    // commands["TERNAK"] = new Ternak();
    // commands["BANGUN_BANGUNAN"] = new BangunBangunan();
    commands["MAKAN"] = new Makan();
    // commands["KASIH_MAKAN"] = new MemberiPangan();
    // commands["BELI"] = new Membeli();
    // commands["JUAL"] = new Menjual();
    // commands["PANEN"] = new Memanen();
    // commands["MUAT"] = new Muat();
    // commands["SIMPAN"] = new Simpan();
    commands["TAMBAH_PEMAIN"] = new TambahPemain();
}

Main::~Main()
{
    for (auto &command : commands)
    {
        delete command.second;
    }
    for (auto &p : *pemain)
    {
        delete p;
    }
}

bool Main::getIsRunning()
{
    return isRunning;
}

void Main::runCommand(string commandInput)
{
    Commands *command = commands[commandInput];
    if (command != nullptr)
    {
        command->run(*this);
    }
    else
    {
        throw RunCommandException();
    }
}

int Main::getUrutanPemain()
{
    return currentPemain;
}

int Main::getBanyakPemain()
{
    return pemain->size();
}

void Main::setUrutanPemain(int currentPemain)
{
    this->currentPemain = currentPemain;
}

Pemain *Main::getCurrentPemain()
{
    return pemain->at(currentPemain);
}

vector<Pemain *> *Main::getPemain()
{
    return pemain;
}

vector<Plant *> *Main::getPlantData()
{
    return &plantData;
}

vector<Animal *> *Main::getAnimalData()
{
    return &animalData;
}

vector<Product> *Main::getProductData()
{
    return &productData;
}