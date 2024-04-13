#include "Main.hpp"
#include "./commands/Next.hpp"
#include "./commands/CetakPenyimpanan.hpp"
// #include "classes/commands/PungutPajak.hpp"
// #include "classes/commands/CetakLadang.hpp"
// #include "classes/commands/CetakPeternakan.hpp"
// #include "classes/commands/Tanam.hpp"
// #include "classes/commands/Ternak.hpp"
// #include "classes/commands/BangunBangunan.hpp"
// #include "classes/commands/Makan.hpp"
// #include "classes/commands/MemberiPangan.hpp"
// #include "classes/commands/Membeli.hpp"
// #include "classes/commands/Menjual.hpp"
// #include "classes/commands/Memanen.hpp"
// #include "classes/commands/Muat.hpp"
// #include "classes/commands/Simpan.hpp"
// #include "classes/commands/TambahPemain.hpp"

#include <iostream>

using namespace std;

Main::Main()
{
    // try
    // {
    //     config.loadConfig(plantData, animalData, productData, bangunanData);
    // }
    // catch (const char *msg)
    // {
    //     cerr << "Exception: " << msg << endl;
    // }
    isRunning = true;
    currentPemain = 0;

    pemain = new vector<Pemain *>();

    menuController.showMenuAwal();
    menuController.opsiBacaState(*pemain);

    commands["NEXT"] = new Next();
    commands["CETAK_PENYIMPANAN"] = new CetakPenyimpanan();
    // commands["PUNGUT_PAJAK"] = new PungutPajak();
    // commands["CETAK_LADANG"] = new CetakLadang();
    // commands["CETAK_PETERNAKAN"] = new CetakPeternakan();
    // commands["TANAM"] = new Tanam();
    // commands["TERNAK"] = new Ternak();
    // commands["BANGUN_BANGUNAN"] = new BangunBangunan();
    // commands["MAKAN"] = new Makan();
    // commands["KASIH_MAKAN"] = new MemberiPangan();
    // commands["BELI"] = new Membeli();
    // commands["JUAL"] = new Menjual();
    // commands["PANEN"] = new Memanen();
    // commands["MUAT"] = new Muat();
    // commands["SIMPAN"] = new Simpan();
    // commands["TAMBAH_PEMAIN"] = new TambahPemain();
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
        throw "Command not found";
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