/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: miejsca.cpp
    Data: 20.01.2022
    Modyfikacja: 15.07.2022
*/

#include <iostream>
#include "../inc/miejsca.h"

using namespace std;

Miejsce::Miejsce() {
    cout << "Poprawnie stworzono konstruktor (Miejsca)!\n";
}

Miejsce::~Miejsce() {
    cout << "Poprawnie zniszczono konstruktor (Miejsca)!\n";
}

void Miejsce::setMiejsce(string n, double odl) {
    this->nazwa = n;
    this->odleglosc = odl;
}

string Miejsce::getNazwa(void) {
    return this->nazwa;
}

double Miejsce::getOdleglosc(void) {
    return this->odleglosc;
}