#include "PungutPajak.hpp"
#include "../Walikota.hpp"
#include "../../utils/Exception.hpp"

#include <iostream>
#include <map>

PungutPajak::PungutPajak()
{
}

PungutPajak::~PungutPajak()
{
}

void PungutPajak::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    Walikota *walikota = dynamic_cast<Walikota *>(pemain);
    map<pair<string, string>, int> pajak;

    if (walikota)
    {
        cout << "Cring cring cring...\nPajak sudah dipungut !" << endl;
        for (Pemain *p : *main.getPemain())
        {
            if (p->getRole() != "Walikota")
                pajak[std::make_pair(p->getUsername(), p->getRole())] = walikota->tagihPajak(p);
        }

        cout << "Berikut adalah detil dari pemungutan pajak:\n";

        // sort the pajak second
        vector<pair<pair<string, string>, int>> pajakVector(pajak.begin(), pajak.end());

        int i = 1;

        for (auto &p : pajakVector)
        {
            cout << i << ". " << p.first.first << " - " << p.first.second << " : " << p.second << " gulden." << endl;
            i++;
        }

        int totalPajak = 0;
        for (auto &p : pajak)
        {
            totalPajak += p.second;
        }

        cout
            << "Negara mendapatkan pemasukan sebesar " << totalPajak << " gulden." << endl;
        cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
    }
    else
    {
        throw WalikotaException();
    }
}