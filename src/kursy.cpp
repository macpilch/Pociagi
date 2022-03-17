#include <iostream>
#include "../inc/funkcje.h"
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
}

Kurs::Kurs(int n, Godzina cz) : Kurs()
{
    this->numer = n;
    this->czas_wyjazdu = cz;
}

void Kurs::obliczanie_czasu(int nr_m, int nr_p) {
    int pred_pociagu = 0;
    int odleglosc = 0;
    int godz = 0;
    int min = 0;

    pred_pociagu = myPociagi[nr_p].get_predkosc();
    odleglosc = myMiejsca[nr_m].get_odleglosc();
    czas_podrozy = (odleglosc / pred_pociagu) * 3600;
}