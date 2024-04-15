#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <string>
#include <map>
#include "Matrix.hpp"

class Pemain
{
protected:
    Matrix<string> *penyimpanan;
    
    string username;
    int gulden;
    int beratbadan;

public:
    Pemain(string username, int gulden, int beratbadan);
    virtual ~Pemain();

    string getUsername();
    void setGulden(int gulden);
    int getGulden();
    void setBeratBadan(int beratbadan);
    int getBeratBadan();
    void tambahPenyimpanan(string kode);
    void cetakPenyimpanan();
    void makan();

    virtual void membeli();
    virtual void menjual();
    virtual string getRole() = 0;
};

#endif