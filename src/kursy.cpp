#include <iostream>
#include "../inc/kursy.h"

using namespace std;

Kurs::Kurs()
{
    numer = 0;
    czas_podrozy = 0;
    czas_wyjazdu.godz = 0;
    czas_wyjazdu.min = 0;
    czas_przyjazdu.godz = 0;
    czas_przyjazdu.min = 0;
    odleglosc = 0;
}

Kurs::Kurs(int n, Godzina cz, int odl) : Kurs()
{
    this->numer = n;
    this->czas_wyjazdu = cz;
    this->odleglosc = odl;
}