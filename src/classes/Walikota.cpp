#include "Walikota.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"
Walikota::Walikota(string username, int gulden, int beratbadan) : Pemain(username, gulden, beratbadan)
{
}

Walikota::~Walikota()
{
}

int Walikota::tagihPajak(Pemain *&pemain)
{
    int kkp;
    if (pemain->getRole() == "Petani")
    {
        kkp = pemain->getGulden() - 13;
    }
    else if (pemain->getRole() == "Peternak")
    {
        kkp = pemain->getGulden() - 11;
    }

    int hasilTagihan;

    if (kkp > 500)
    {
        hasilTagihan = kkp - (kkp * 0.35);
    }
    else if (kkp > 50)
    {
        hasilTagihan = kkp - (kkp * 0.3);
    }
    else if (kkp > 25)
    {
        hasilTagihan = kkp - (kkp * 0.25);
    }
    else if (kkp > 6)
    {
        hasilTagihan = kkp - (kkp * 0.15);
    }
    else if (kkp > 0)
    {
        hasilTagihan = kkp - (kkp * 0.05);
    }
    pemain->setGulden(hasilTagihan);
    this->setGulden(hasilTagihan);
    return hasilTagihan;
}

void Walikota::bangunBangunan()
{
    // TODO
}

void Walikota::tambahPemain(vector<Pemain*> &pemain) {
    int uang = getGulden();
    if (uang < 50) {
        cout << "Uang tidak cukup!" << endl;
        return;
    }

    string jenisPemain;
    string namaPemain;

    cout << "Masukkan jenis pemain: ";
    cin >> jenisPemain;

    if (jenisPemain != "peternak" && jenisPemain != "petani") {
        cout << "Jenis pemain tidak valid!" << endl;
        return;
    }

    cout << "Masukkan nama pemain: ";
    cin >> namaPemain;

    for (Pemain *p : pemain) {
        if (p->getUsername() == namaPemain) {
            cout << "Nama pemain sudah ada!" << endl;
            return;
        }
    }

    uang -= 50;
    setGulden(uang);

    Pemain* newPlayer;
    if (jenisPemain == "peternak") {
        newPlayer = new Peternak(namaPemain, 0, 0); // Membuat objek peternak
    } else if (jenisPemain == "petani") {
        newPlayer = new Petani(namaPemain, 0, 0); // Membuat objek petani
    }
    pemain.push_back(newPlayer);

    cout << "Pemain baru ditambahkan!" << endl;
    cout << "Selamat datang \"" << namaPemain << "\" di kota ini!" << endl;
}

string Walikota::getRole()
{
    return "Walikota";
}