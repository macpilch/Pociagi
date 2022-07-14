#include <iostream>
#include "../inc/miejsca.h"

using namespace std;

Miejsce::Miejsce() {
    cout << "Poprawnie stworzono konstruktor (Miejsca)!\n";
}

Miejsce::~Miejsce() {
    
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