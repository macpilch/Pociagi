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

Kurs::Kurs(int n, int godz, int min) : Kurs()
{
    this->numer = n;
    this->czas_wyjazdu.godz = godz;
    this->czas_wyjazdu.min = min;
}

int Kurs::get_numer(void) {
    return this->numer;
}

int Kurs::get_czas_wyjazdu_godz(void) {
    return this->czas_wyjazdu.godz;
}

int Kurs::get_czas_wyjazdu_min(void) {
    return this->czas_wyjazdu.min;
}

void Kurs::set_kurs(int n, int godz, int min) {
    this->numer = n;
    this->czas_wyjazdu.godz = godz;
    this->czas_wyjazdu.min = min;
}

void Kurs::obliczanie_czasu(int nr_m, int nr_p) {
    int pred_pociagu = 0;
    int odleglosc = 0;
    int godz = 0;
    int min = 0;

    pred_pociagu = myPociagi[nr_p].get_predkosc();
    odleglosc = myMiejsca[nr_m].get_odleglosc();
    czas_podrozy = (odleglosc / pred_pociagu) * 3600;
    godz = czas_podrozy / 3600;
    czas_podrozy %= 3600;
    min = czas_podrozy / 60;
    czas_przyjazdu.godz = czas_wyjazdu.godz + godz;
    czas_przyjazdu.min = czas_wyjazdu.min + min;
}