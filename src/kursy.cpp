#include <iostream>
#include "../inc/funkcje.h"
#include "../inc/kursy.h"

using namespace std;

Kurs::Kurs() {
    czasPodrozy = 0;
    czasWyjazdu.godz = 0;
    czasWyjazdu.min = 0;
    czasPrzyjazdu.godz = 0;
    czasPrzyjazdu.min = 0;

    cout << "Poprawnie stworzono konstruktor (Kursy)!" << endl;
}

Kurs::Kurs(int godz, int min) : Kurs() {
    this->czasWyjazdu.godz = godz;
    this->czasWyjazdu.min = min;
}

int Kurs::getCzasWyjazduGodz(void) {
    return this->czasWyjazdu.godz;
}

int Kurs::getCzasWyjazduMin(void) {
    return this->czasWyjazdu.min;
}

void Kurs::setKurs(int godz, int min) {
    this->czasWyjazdu.godz = godz;
    this->czasWyjazdu.min = min;
}