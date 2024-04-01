#include "Pemain.hpp"
#include "Hewan.hpp"
using namespace std;

class Peternak : public Pemain
{
private:
    vector<Hewan> hewan_ladang;

public:
    Peternak();
    Peternak(string nama, int uang, int bb);
    ~Peternak();

    void menaruhHewan(const Hewan &);
    Hewan getHewan(int id);
    void beriMakanHewan(int id);
    void panenHewan(int id);
};