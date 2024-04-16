#include "Membeli.hpp"

#include <iostream>

Membeli::Membeli()
{
}

Membeli::~Membeli()
{
}

void Membeli::run(Main &main)
{
    Pemain *pemain = main.getCurrentPemain();
    Toko *toko = main.getToko();
    toko->showItems();

    int slotTersedia = (pemain->getPenyimpanan()->getCol() * pemain->getPenyimpanan()->getRow()) - pemain->getPenyimpanan()->getNEff();
    cout
        << "Uang anda: " << pemain->getGulden() << endl;
    cout << "Slot penyimpanan tersedia: " << slotTersedia << endl;

    int index;
    int banyak;
    cout << "Barang ingin dibeli: ";
    cin >> index;
    do
    {
        cout << "Kuantitas: ";
        cin >> banyak;
        if (banyak > slotTersedia)
        {
            cout << "Slot penyimpanan tidak cukup\n"
                 << endl;
        }
    } while (banyak > slotTersedia);

    cout << "Selamat Anda berhasil membeli " << banyak << " " << toko->getNamaItem(index) << ". Uang Anda tersisa " << pemain->getGulden() << " gulden." << endl;

    try
    {
        pemain->membeli(toko, index, banyak);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
}