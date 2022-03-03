#include <iostream>
#include "../inc/pociagi.h"

using namespace std;

void Pociag::set_pociag_nazwa(string n) {
    this->nazwa = n;
}

void Pociag::set_pociag_pred(int p) {
    this->predkosc = p;
}

string Pociag::get_nazwa(void) {
    return this->nazwa;
}

int Pociag::get_predkosc(void) {
    return this->predkosc;
}