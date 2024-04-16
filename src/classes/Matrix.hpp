#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <ostream>
using namespace std;

template <class T>
class Matrix
{
private:
    T **elmt;
    int row;
    int col;
    int nEff;

public:
    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        this->elmt = new T *[row];
        for (int i = 0; i < row; i++)
        {
            this->elmt[i] = new T[col];
        }
        this->nEff = 0;
    }
    ~Matrix()
    {
        for (int i = 0; i < this->row; i++)
        {
            delete[] this->elmt[i];
        }
        delete[] this->elmt;
    }

    void setElmt(int row, int col, T value)
    {
        this->elmt[row][col] = value;
    }

    T getElmt(int row, int col)
    {
        return this->elmt[row][col];
    }

    int getRow()
    {
        return this->row;
    }
    int getCol()
    {
        return this->col;
    }

    int getNEff()
    {
        return this->nEff;
    }

    friend ostream &operator<<(ostream &os, Matrix &m)
    {
        int n_digit = to_string(m.getRow()).length();

        for (int i = 0; i < m.getRow(); i++)
        {
            if (i == 0)
            {
                for (int k = 0; k < m.getCol(); k++)
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
                    for (int k = 0; k < m.getCol(); k++)
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
                    for (int k = 0; k < m.getCol(); k++)
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
                        if (m.getElmt(i, k) == "")
                        {
                            os << "|     ";
                        }
                        else
                        {
                            os << "| " << m.getElmt(i, k);
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
            if (i == m.getRow() - 1)
            {
                for (int k = 0; k < m.getCol(); k++)
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
};

#endif