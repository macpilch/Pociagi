#include <iostream>
#include "../inc/tory.h"

using namespace std;

void Tor::set_poczatek(int p) {
    this->poczatek = p;
}

void Tor::set_dostepnosc(bool b) {
    this->dostepnosc = b;
}

int Tor::get_poczatek(void) {
    return poczatek;
}

int Tor::get_koniec(void) {
    return koniec;
}

bool Tor::get_dostepnosc(void) {
    return dostepnosc;
}