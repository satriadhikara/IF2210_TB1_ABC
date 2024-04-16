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

            string rowString;
            string colString;

            string slot;
            cin >> slot;

            for (char c : slot)
            {
                if (isdigit(c))
                {
                    rowString += c;
                }
                else
                {
                    colString += c;
                }
            }

            int row = stoi(rowString);

            int col = 0;
            for (char c : colString)
            {
                row = row * 26 + (c - 'A');
            };

            if (pemain)
            {
                try
                {
                    pemain->makan(*main.getProductData(), row, col);
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