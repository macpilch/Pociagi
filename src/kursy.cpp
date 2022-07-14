#include <iostream>
#include "../inc/kursy.h"

using namespace std;

Kurs::Kurs() {
    czasPodrozy = 0;
    czasWyjazdu.godz = 0;
    czasWyjazdu.min = 0;
    czasPrzyjazdu.godz = 0;
    czasPrzyjazdu.min = 0;

    cout << "Poprawnie stworzono konstruktor (Kursy)!\n";
}

Kurs::~Kurs() {
    
}

Kurs::Kurs(int godz, int min) : Kurs() {
    this->czasWyjazdu.godz = godz;
    this->czasWyjazdu.min = min;
}

void Kurs::setKurs(int godz, int min) {
    this->czasWyjazdu.godz = godz;
    this->czasWyjazdu.min = min;
}