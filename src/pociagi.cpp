#include <iostream>
#include "../inc/pociagi.h"

using namespace std;

Pociag::Pociag()
{
    cout << "Poprawnie stworzono konstruktor (Pociagi)!" << endl;
}

void Pociag::set_pociag(string n, double p)
{
    this->nazwa = n;
    this->predkosc = p;
}

string Pociag::get_nazwa(void)
{
    return this->nazwa;
}

double Pociag::get_predkosc(void)
{
    return this->predkosc;
}