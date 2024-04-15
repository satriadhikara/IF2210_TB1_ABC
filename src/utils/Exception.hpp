#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
using namespace std;

struct CetakPenyimpananException : public exception
{
    const char *what() const throw()
    {
        return "Pointer pemain kosong.\n";
    }
};

struct PungutPajakException : public exception
{
    const char *what() const throw()
    {
        return "Role salah.\n";
    }
};

struct CetakLadangException : public exception
{
    const char *what() const throw()
    {
        return "Pemain bukan petani.\n";
    }
};

struct CetakPeternakanException : public exception
{
    const char *what() const throw()
    {
        return "Pemain bukan peternak.\n";
    }
};
#endif