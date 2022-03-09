#include <iostream>
#include "../inc/tory.h"

using namespace std;

Tor::Tor()
{
    cout << "Poprawnie stworzono konstruktor (Tory)!\n";
}

void Tor::set_tor(int n, int p, int k)
{
    this->numer = n;
    this->poczatek = p;
    this->koniec = k;
}

int Tor::get_numer(void)
{
    return this->numer;
}

int Tor::get_poczatek(void)
{
    return this->poczatek;
}

int Tor::get_koniec(void)
{
    return this->koniec;
}