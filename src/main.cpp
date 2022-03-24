#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

int main(void)
{
    wczytaj_miejsce();
    wczytaj_pociagi();
    wczytaj_kursy();
    pokaz_menu();
    return 0;
}

void pokaz_menu(void)
{
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl;
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. MIEJSCA.\n2. POCIAGI.\n3. KURSY.\n4. PODSUMOWANIE.\n";
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
        pokaz_elementy_kursow();
        break;
    case 4:
        system("cls");
        pokaz_podsumowanie();
        break;
    }
}

void pokaz_podsumowanie(void)
{
    cout << "Wszystkie dane biletu: " << endl;
    cout << "Miejscowosc: " << myMiejsca[nr_miejsca - 1].get_nazwa() << endl;
    cout << "Pociag: " << myPociagi[nr_pociagu - 1].get_nazwa() << endl;
    cout << "Czas wyjazdu pociagu: " << myKursy[nr_kursu - 1].get_czas_wyjazdu_godz();
    cout << ":" << myKursy[nr_kursu - 1].get_czas_wyjazdu_min() << endl;
    cout << "Czas przyjazdu pociagu: " << myKursy[nr_kursu - 1].czas_przyjazdu.godz;
    cout << ":" << myKursy[nr_kursu - 1].czas_przyjazdu.min << endl;

    if (getch())
    {
        system("cls");
        pokaz_menu();
    }
}