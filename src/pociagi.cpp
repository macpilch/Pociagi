#include <iostream>
#include "../inc/pociagi.h"

using namespace std;

Pociag::Pociag() {
    cout << "Poprawnie stworzono konstruktor (Pociagi)!" << endl;
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