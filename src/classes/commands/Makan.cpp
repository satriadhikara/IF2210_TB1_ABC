#include "Makan.hpp"
#include "CetakPenyimpanan.hpp"

#include <iostream>
#include <cctype>
#include <algorithm>

Makan::Makan()
{
}

Makan::~Makan()
{
}

void Makan::run(Main &main)
{

    Pemain *pemain = main.getCurrentPemain();

    bool bisa = false;

    if (pemain)
    {
        Matrix<string> *penyimpanan = pemain->getPenyimpanan();
        if (penyimpanan)
        {
            if (penyimpanan->getNEff() == 0)
            {
                throw "Penyimpanan kosong!";
            }
            else
            {
                for (int i = 0; i < penyimpanan->getRow(); i++)
                {
                    for (int j = 0; j < penyimpanan->getCol(); j++)
                    {
                        if (penyimpanan->getElmt(i, j) != "")
                        {
                            for (Product p : *main.getProductData())
                            {
                                if (p.getKodeHuruf() == penyimpanan->getElmt(i, j))
                                {
                                    bisa = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!bisa)
    {
        throw "Tidak ada makanan yang bisa dimakan!";
    }
    else
    {
        bool success = false;
        while (!success)
        {
            cout << "Pilih makanan dari penyimpanan" << endl;
            CetakPenyimpanan cp;
            cp.run(main);
            Pemain *pemain = main.getCurrentPemain();

            string slot;
            cin >> slot;

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

            if (pemain)
            {
                try
                {
                    pemain->makan(*main.getProductData(), baris, kolom);
                    success = true;
                }
                catch (exception &e)
                {
                    cout << e.what() << endl;
                }
            }
        }
    }
}