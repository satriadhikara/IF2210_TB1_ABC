#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "../utils/includes.hpp"

class Pemain
{
protected:
    int uang;
    int bb;

public:
    /**
     * @brief default uang = 50, berat badan = 40
     *
     */
    Pemain();

    /**
     * @brief
     *
     * @param uang (gulden)
     * @param bb
     */
    Pemain(int uang, int bb);

    virtual ~Pemain();

    /**
     * @brief Menampilkan matriks penyimpanan
     *
     */
    virtual void showPenyimpanan();

    void setUang(int uang);
    int getUang();
    void setBB(int bb);
    int getBB();
};

#endif
