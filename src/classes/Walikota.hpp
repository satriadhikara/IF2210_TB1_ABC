#include "Pemain.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"

using namespace std;

class Walikota : public Pemain
{
public:
    Walikota();
    Walikota(int uang, int bb);
    ~Walikota();

    /**
     * @brief
     *
     * @param petani
     * @param peternak
     */
    void pungutPajak(vector<Petani> &petani, vector<Peternak> &peternak);

    /**
     * @brief (nanti aja)
     *
     */
    void bangunBangunan();

    /**
     * @brief menambahkan akun petani dengan jumlah uang bawaan 50 gulden dengan mengurangi uang walikota
     *
     * @param petani (reference)
     */
    void tambahAkunPetani(vector<Petani> &petani);

    /**
     * @brief menambahkan akun peternak dengan jumlah uang bawaan 50 gulden dengan mengurangi uang walikota
     *
     * @param peternak (reference)
     */
    void tambahAkunPeternak(vector<Peternak> &peternak);
};