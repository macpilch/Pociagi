#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

int main(void)
{
    /*Godzina tmp;
    tmp.godz = 8;
    tmp.min = 15;
    Kurs k1(1, tmp, 100);

    cout << "Numer: " << k1.numer << " Odleglosc: " << k1.odleglosc << " Godzina: " 
         << k1.czas_wyjazdu.godz << " Czas podrozy: " << k1.czas_podrozy;*/
    wczytaj_miejsce();
    wczytaj_pociagi();
    pokaz_menu();
    return 0;
}

void pokaz_menu(void)
{
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl;
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. MIEJSCA.\n2. POCIAGI.\n3. KURSY.\n";
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
        //pokaz_elementy_kursow();
        break;
    }
}