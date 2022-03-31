#include <iostream>
#include "../inc/miejsca.h"

using namespace std;

Miejsce::Miejsce()
{
    cout << "Poprawnie stworzono konstruktor (Miejsca)!\n";
}

void Miejsce::set_miejsce(string n, double odl)
{
    this->nazwa = n;
    this->odleglosc = odl;
}

string Miejsce::get_nazwa(void)
{
    return this->nazwa;
}

double Miejsce::get_odleglosc(void)
{
    return this->odleglosc;
}