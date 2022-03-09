#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

int main(void)
{
    wczytaj_miejsce();
    wczytaj_pociagi();
    wczytaj_tory();
    pokaz_menu();
    return 0;
}

void pokaz_menu(void)
{
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl;
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. MIEJSCA.\n2. POCIAGI.\n3. TORY.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_elementy_miejsc();
        break;
    case 2:
        system("cls");
        pokaz_elementy_pociagow();
        break;
    case 3:
        system("cls");
        pokaz_elementy_torow();
        break;
    }
}