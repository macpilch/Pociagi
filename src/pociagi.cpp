/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: pociagi.cpp
    Data: 20.01.2022
    Modyfikacja: 19.07.2022
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

void Pociag::setPociag(string n, double p) {
    this->nazwa = n;
    this->predkosc = p;
}

string Pociag::getNazwa(void) {
    return this->nazwa;
}

double Pociag::getPredkosc(void) {
    return this->predkosc;
}