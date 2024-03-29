/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: main.cpp
    Data: 13.01.2022
    Modyfikacja: 23.07.2022
*/

#define LICENCJA
#ifdef LICENCJA

#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

VECM myMiejsca;
VECP myPociagi;
VECK myKursy;

int main(int argc, char **argv) {
    cout << "Argc: " << argc << endl;
    cout << "Argv: " << argv[0] << endl;
    
    wczytajMiejsca(myMiejsca);
    wczytajPociagi(myPociagi);
    wczytajKursy(myKursy);
    pokazMenu();
    return 0;
}

#else

#error Brak licencji! Nie mozna skompilowac programu.
#endif