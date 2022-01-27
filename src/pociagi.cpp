#include <iostream>
#include "../inc/pociagi.h"

using namespace std;

void Pociag::set_pociag_nazwa(string n) {
    this->nazwa = n;
}

void Pociag::set_pociag_pred(int p) {
    this->predkosc = p;
}

void Pociag::set_pociag_dost(bool d) {
    this->dostepnosc = d;
}

string Pociag::get_nazwa(void) {
    return this->nazwa;
}

int Pociag::get_predkosc(void) {
    return this->predkosc;
}

bool Pociag::get_dostepnosc(void) {
    return this->dostepnosc;
}