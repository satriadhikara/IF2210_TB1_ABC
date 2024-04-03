#include "Matrix.hpp"

template <typename T>
Matrix<T>::Matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    this->elmt = new T *[row];
    for (int i = 0; i < row; i++)
    {
        this->elmt[i] = new T[col];
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < this->row; i++)
    {
        delete[] this->elmt[i];
    }
    delete[] this->elmt;
}

template <typename T>
void Matrix<T>::setElmt(int row, int col, T value)
{
    // TODO: bikin exception
    // if (row < 0 || row >= this->row || col < 0 || col >= this->col)
    // {
    //     throw "Index out of bound";
    // }
    this->elmt[row][col] = value;
}

template <typename T>
T Matrix<T>::getElmt(int row, int col)
{
    for (int i = 0; i < data_hewan_ternak.size(); i++)
    {
        if (data_hewan_ternak[i].getKode() == elmt[row][col)
        {
            return data_hewan_ternak[i];
        }
    }
}

template <typename T>
ostream &operator<<(ostream &os, const Matrix<T> &matrix)
{
    int n = matrix.row;
    int m = matrix.col;
    int n_digit = to_string(n).length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix.elmt[i][j] = "   ";
        }
    }

    // matrix[4][3] = "COW";
    // contoh penggunaan

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (int k = 0; k < m; k++)
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
                for (int k = 0; k < m; k++)
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
                for (int k = 0; k < m; k++)
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
                    os << "| " << matrix.elmt[i][k];
                    for (int l = 0; l < str.length(); l++)
                    {
                        os << " ";
                    }
                }
                os << "|" << endl;
            }
        }
        if (i == n - 1)
        {
            for (int k = 0; k < m; k++)
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