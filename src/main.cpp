#define LICENCJA
#ifdef LICENCJA
#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

vector<Miejsce> myMiejsca;
vector<Pociag> myPociagi;
vector<Kurs> myKursy;

int main(int argc, char **argv) {
    cout << "Argv: " << argv[1] << endl;
    
    wczytajMiejsce(myMiejsca);
    wczytajPociagi(myPociagi);
    wczytajKursy(myKursy);
    pokazMenu();
    return 0;
}
#else
#error Brak licencji! Nie mozna skompilowac programu.
#endif