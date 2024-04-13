#ifndef MATRIX_HPP
#define MATRIX_HPP

using namespace std;
#include <ostream>

template <class T>
class Matrix
{
private:
    T **elmt;
    int row;
    int col;

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
    friend ostream &operator<<(ostream &os, const Matrix &m)
    {
        for (int i = 0; i < m->getRow(); i++)
        {
            for (int j = 0; j < m->getCol(); j++)
            {
                os << m->getElmt(i, j) << " ";
            }
            os << endl;
        }
        return os;
    }
};

#endif