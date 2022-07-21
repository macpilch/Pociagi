/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: pociagi.cpp
    Data: 20.01.2022
    Modyfikacja: 20.07.2022
*/

#include <iostream>
#include "../inc/pociagi.h"

using namespace std;

Pociag::Pociag() {
    cout << "Poprawnie stworzono konstruktor (Pociagi)!" << endl;
}

Pociag::~Pociag() {
    cout << "Poprawnie zniszczono konstruktor (Pociagi)!" << endl;
}

void Pociag::setPociag(string n, double p, bool d) {
    this->nazwa = n;
    this->predkosc = p;
    this->dostepnosc = d;
}

string Pociag::getNazwa(void) {
    return this->nazwa;
}

double Pociag::getPredkosc(void) {
    return this->predkosc;
}

void Pociag::setDostepnosc(bool d) {
    this->dostepnosc = d;
}

bool Pociag::getDostepnosc(void) {
    return this->dostepnosc;
}