#include <iostream>
#include "../inc/miejsca.h"

using namespace std;

Miejsce::Miejsce() {
    cout << "Poprawnie stworzono konstruktor (Miejsca)!\n";
}

void Miejsce::set_miejsce(string n, int odl, bool s) {
    this->nazwa = n;
    this->odleglosc = odl;
    this->stworzone = s;
}

string Miejsce::get_nazwa(void) {
    return this->nazwa;
}

int Miejsce::get_odleglosc(void) {
    return this->odleglosc;
}

bool Miejsce::get_stworzone(void) {
    return this->stworzone;
}