#include "Next.hpp"
#include <iostream>

Next::Next()
{
}

Next::~Next()
{
}

void Next::run(Main &main)
{
    int temp = main.getCurrentPemain();
    main.setCurrentPemain((temp + 1) % main.getBanyakPemain());
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
}