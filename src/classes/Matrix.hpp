#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../utils/includes.hpp"
using namespace std;

template <class T>
class Matrix
{
protected:
    int row;
    int col;
    T **elmt;

public:
    Matrix(int row, int col);
    ~Matrix();

    void setElmt(int row, int col, T value);
    T getElmt(int row, int col);
    friend ostream &operator<<(ostream &os, const Matrix<T> &matrix) {}
};

#endif