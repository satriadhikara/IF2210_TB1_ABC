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

#endif