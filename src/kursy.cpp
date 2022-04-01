#include <iostream>
#include "../inc/funkcje.h"
#include "../inc/kursy.h"

using namespace std;

Kurs::Kurs()
{
    czas_podrozy = 0;
    czas_wyjazdu.godz = 0;
    czas_wyjazdu.min = 0;
    czas_przyjazdu.godz = 0;
    czas_przyjazdu.min = 0;

    cout << "Poprawnie stworzono konstruktor (Kursy)!" << endl;
}

Kurs::Kurs(int godz, int min) : Kurs()
{
    this->czas_wyjazdu.godz = godz;
    this->czas_wyjazdu.min = min;
}

int Kurs::get_czas_wyjazdu_godz(void)
{
    return this->czas_wyjazdu.godz;
}

int Kurs::get_czas_wyjazdu_min(void)
{
    return this->czas_wyjazdu.min;
}

void Kurs::set_kurs(int godz, int min)
{
    this->czas_wyjazdu.godz = godz;
    this->czas_wyjazdu.min = min;
}