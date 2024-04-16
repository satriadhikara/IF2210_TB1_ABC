#include "Peternakan.hpp"

Peternakan::Peternakan(int row, int col) : Matrix<Animal *>(row, col) {}

Peternakan::~Peternakan()
{
    // for (int i = 0; i < this->getRow(); i++)
    // {
    //     for (int j = 0; j < this->getCol(); j++)
    //     {
    //         delete this->getElmt(i, j);
    //     }
    // }
}

void Peternakan::setAnimal(int row, int col, Animal *animal)
{
    this->setElmt(row, col, animal);
}

bool Peternakan::isFull()
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

ostream &operator<<(ostream &os, Peternakan &p)
{
    {
        int n_digit = to_string(p.getRow()).length();

        for (int i = 0; i < p.getRow(); i++)
        {
            if (i == 0)
            {
                for (int k = 0; k < p.getCol(); k++)
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
                    for (int k = 0; k < p.getCol(); k++)
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
                            for (int p = 0; p < n_digit; p++)
                            {
                                os << " ";
                            }
                            os << " ";
                        }
                        os << "+----";
                        for (int p = 0; p < str.length(); p++)
                        {
                            os << "-";
                        }
                    }
                    os << "+" << endl;
                }
                else
                {
                    for (int k = 0; k < p.getCol(); k++)
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
                            for (int p = 0; p < n_digit; p++)
                            {
                                int temp_digit = to_string(i + 1).length();
                                if (p < n_digit - temp_digit)
                                {
                                    os << "0";
                                }
                                else
                                {
                                    os << to_string(i + 1)[p - n_digit + temp_digit];
                                }
                            }
                            os << " ";
                        }
                        if (p.getElmt(i, k) == nullptr)
                        {
                            os << "|     ";
                        }
                        else
                        {
                            if (p.getElmt(i, k)->isSiapPanen())
                            {
                                os << "| ";
                                os << PColor::green << p.getElmt(i, k)->getKodeHuruf() << PColor::normal;
                            }
                            else
                            {
                                os << "| ";
                                os << PColor::red << p.getElmt(i, k)->getKodeHuruf() << PColor::normal;
                            }

                            for (int p = 0; p < str.length(); p++)
                            {
                                os << " ";
                            }
                        }

                        
                        // os << "| " << m.getElmt(i, k);
                        // for (int p = 0; p < str.length(); p++)
                        // {
                        //     os << " ";
                        // }
                    }
                    os << "|" << endl;
                }
            }
            if (i == p.getRow() - 1)
            {
                for (int k = 0; k < p.getCol(); k++)
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
                        for (int p = 0; p < n_digit; p++)
                        {
                            os << " ";
                        }
                        os << " ";
                    }
                    os << "+----";
                    for (int p = 0; p < str.length(); p++)
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
