#include "Ladang.hpp"

#include <vector>
#include <algorithm>

Ladang::Ladang(int row, int col) : Matrix<Plant *>(row, col) {}

Ladang::~Ladang()
{
    // for (int i = 0; i < this->getRow(); i++)
    // {
    //     for (int j = 0; j < this->getCol(); j++)
    //     {
    //         delete this->getElmt(i, j);
    //     }
    // }
}

void Ladang::setPlant(int row, int col, Plant *plant)
{
    this->setElmt(row, col, plant);
}

bool Ladang::isFull()
{
    for (int i = 0; i < this->getRow(); i++)
    {
        for (int j = 0; j < this->getCol(); j++)
        {
            if (this->getElmt(i, j) == nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

void Ladang::listTumbuhan()
{
    vector<Plant*> kodeHuruf;
    for (int i = 0; i < this->getRow(); i++)
    {
        for (int j = 0; j < this->getCol(); j++)
        {
            if (this->getElmt(i, j) != nullptr)
            {
                if (find(kodeHuruf.begin(), kodeHuruf.end(), this->getElmt(i, j)->getKodeHuruf()) == kodeHuruf.end())
                {
                    kodeHuruf.push_back(this->getElmt(i, j));
                }
            }
        }
    }

    for (int i = 0; i < kodeHuruf.size(); i++)
    {
        cout << "- " << kodeHuruf[i]->getKodeHuruf() << ": " << kodeHuruf[i]->getNama() << endl;
    }
}

void Ladang::listSiapPanen()
{
    vector<Plant*> kodeHuruf;
    for (int i = 0; i < this->getRow(); i++)
    {
        for (int j = 0; j < this->getCol(); j++)
        {
            if (this->getElmt(i, j) != nullptr)
            {
                if (this->getElmt(i, j)->isSiapPanen())
                {
                    if (find(kodeHuruf.begin(), kodeHuruf.end(), this->getElmt(i, j)->getKodeHuruf()) == kodeHuruf.end())
                    {
                        kodeHuruf.push_back(this->getElmt(i, j));
                    }
                }
            }
        }
    }

    for (int i = 0; i < kodeHuruf.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < this->getRow(); j++)
        {
            for (int k = 0; k < this->getCol(); k++)
            {
                if (this->getElmt(j, k) != nullptr)
                {
                    if (this->getElmt(j, k)->getKodeHuruf() == kodeHuruf[i]->getKodeHuruf())
                    {
                        count++;
                    }
                }
            }
        }
        cout << i+1 << ". " << kodeHuruf[i]->getKodeHuruf() << " (" << count << "petak siap panen)" << endl;
    }

}

ostream &operator<<(ostream &os, Ladang &l)
{
    {
        int n_digit = to_string(l.getRow()).length();

        for (int i = 0; i < l.getRow(); i++)
        {
            if (i == 0)
            {
                for (int k = 0; k < l.getCol(); k++)
                {
                    if (k == 0)
                    {
                        os << "    ";
                    }
                    os << "    ";
                    int temp = k;
                    string str = "";
                    while (temp >= 0)
                    {
                        str = (char)(65 + (temp % 26)) + str;
                        temp = temp / 26 - 1;
                    }
                    os << str;
                    os << " ";
                }
                os << " " << endl;
            }
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    for (int k = 0; k < l.getCol(); k++)
                    {
                        int temp = k;
                        string str = "";
                        while (temp >= 0)
                        {
                            str = (char)(65 + (temp % 26)) + str;
                            temp = temp / 26 - 1;
                        }
                        if (k == 0)
                        {
                            os << " ";
                            for (int l = 0; l < n_digit; l++)
                            {
                                os << " ";
                            }
                            os << " ";
                        }
                        os << "+----";
                        for (int l = 0; l < str.length(); l++)
                        {
                            os << "-";
                        }
                    }
                    os << "+" << endl;
                }
                else
                {
                    for (int k = 0; k < l.getCol(); k++)
                    {
                        int temp = k;
                        string str = "";
                        while (temp >= 0)
                        {
                            str = (char)(65 + (temp % 26)) + str;
                            temp = temp / 26 - 1;
                        }
                        if (k == 0)
                        {
                            os << " ";
                            for (int l = 0; l < n_digit; l++)
                            {
                                int temp_digit = to_string(i + 1).length();
                                if (l < n_digit - temp_digit)
                                {
                                    os << "0";
                                }
                                else
                                {
                                    os << to_string(i + 1)[l - n_digit + temp_digit];
                                }
                            }
                            os << " ";
                        }
                        if (l.getElmt(i, k) == nullptr)
                        {
                            os << "|     ";
                        }
                        else
                        {
                            if (l.getElmt(i, k)->isSiapPanen())
                            {
                                os << "| ";
                                os << PColor::green << l.getElmt(i, k)->getKodeHuruf() << PColor::normal;
                            }
                            else
                            {
                                os << "| ";
                                os << PColor::red << l.getElmt(i, k)->getKodeHuruf() << PColor::normal;
                            }

                            for (int l = 0; l < str.length(); l++)
                            {
                                os << " ";
                            }
                        }

                        
                        // os << "| " << m.getElmt(i, k);
                        // for (int l = 0; l < str.length(); l++)
                        // {
                        //     os << " ";
                        // }
                    }
                    os << "|" << endl;
                }
            }
            if (i == l.getRow() - 1)
            {
                for (int k = 0; k < l.getCol(); k++)
                {
                    int temp = k;
                    string str = "";
                    while (temp >= 0)
                    {
                        str = (char)(65 + (temp % 26)) + str;
                        temp = temp / 26 - 1;
                    }
                    if (k == 0)
                    {
                        os << " ";
                        for (int l = 0; l < n_digit; l++)
                        {
                            os << " ";
                        }
                        os << " ";
                    }
                    os << "+----";
                    for (int l = 0; l < str.length(); l++)
                    {
                        os << "-";
                    }
                }
                os << "+" << endl;
            }
        }
        return os;
    }
}