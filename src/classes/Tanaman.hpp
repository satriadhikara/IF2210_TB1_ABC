#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "Tipe_Properti.hpp"
using namespace std;

class Tanaman : public Tipe_Properti
{
private:
    static int jumlahTanaman;
    int durasi_panen;

public:
    /**
     * @brief Default constructor
     *
     */
    Tanaman();

    /**
     * @brief
     *
     * @param id
     * @param kode
     * @param nama
     * @param tipe
     * @param durasi_tumbuh
     * @param harga
     */
    Tanaman(int id, string kode, string nama, string tipe, int durasi_tumbuh, int harga);

    /**
     * @brief Copy constructor
     *
     * @param tanaman
     */
    Tanaman(const Tanaman &tanaman);

    /**
     * @brief Destructor
     *
     */
    ~Tanaman();

    /**
     * @brief
     *
     * @param durasi_panen
     */
    void setDurasiPanen(int durasi_panen);

    /**
     * @brief
     *
     * @return int
     */
    int getDurasiPanen();

    static int getJumlahTanaman();
};

#endif