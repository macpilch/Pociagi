#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

int nr_miejsca = -1;
int nr_pociagu = -1;
int nr_kursu = -1;

vector<Miejsce> myMiejsca;
vector<Pociag> myPociagi;
vector<Kurs> myKursy;

int main(void)
{
    wczytaj_miejsce(myMiejsca);
    wczytaj_pociagi(myPociagi);
    wczytaj_kursy(myKursy);
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
        pokaz_elementy_miejsc(myMiejsca, &nr_miejsca);
        break;
    case 2:
        system("cls");
        pokaz_elementy_pociagow(myPociagi, &nr_pociagu);
        break;
    case 3:
        system("cls");
        pokaz_elementy_kursow(myKursy, &nr_kursu);
        break;
    case 4:
        system("cls");
        pokaz_podsumowanie();
        break;
    }
}

void obliczanie_czasu(void)
{
    double pred_pociagu = 0;
    double odleglosc = 0;
    int godz = 0;
    int min = 0;
    int t = 0;

    pred_pociagu = myPociagi[nr_pociagu - 1].get_predkosc();
    odleglosc = myMiejsca[nr_miejsca - 1].get_odleglosc();

    myKursy[nr_kursu - 1].czas_podrozy = (odleglosc / pred_pociagu) * 3600;
    t = myKursy[nr_kursu - 1].czas_podrozy;

    godz = t / 3600;
    t %= 3600;
    min = t / 60;
    t %= 60;

    myKursy[nr_kursu - 1].czas_przyjazdu.godz = myKursy[nr_kursu - 1].czas_wyjazdu.godz + godz;
    myKursy[nr_kursu - 1].czas_przyjazdu.min = myKursy[nr_kursu - 1].czas_wyjazdu.min + min;
}

void pokaz_podsumowanie(void)
{
    cout << "*** Wszystkie dane biletu: ***" << endl;

    if (nr_miejsca != -1)
    {
        cout << "Miejscowosc: " << myMiejsca[nr_miejsca - 1].get_nazwa() << endl;
    }
    else
    {
        cout << "Miejscowosc: Brak." << endl;
    }

    if (nr_pociagu != -1)
    {
        cout << "Pociag: " << myPociagi[nr_pociagu - 1].get_nazwa() << endl;
    }
    else
    {
        cout << "Pociag: Brak." << endl;
    }

    if (nr_kursu != -1)
    {
        obliczanie_czasu();
        cout << "Nr. kursu: " << nr_kursu << endl;

        if (myKursy[nr_kursu - 1].get_czas_wyjazdu_godz() > 9 && myKursy[nr_kursu - 1].get_czas_wyjazdu_godz() < 24)
        {
            cout << "Czas wyjazdu pociagu: " << myKursy[nr_kursu - 1].get_czas_wyjazdu_godz();
        }
        else
        {
            cout << "Czas wyjazdu pociagu: 0" << myKursy[nr_kursu - 1].get_czas_wyjazdu_godz();
        }

        if (myKursy[nr_kursu - 1].get_czas_wyjazdu_min() > 9 && myKursy[nr_kursu - 1].get_czas_wyjazdu_min() < 60)
        {
            cout << ":" << myKursy[nr_kursu - 1].get_czas_wyjazdu_min() << endl;
        }
        else
        {
            cout << ":0" << myKursy[nr_kursu - 1].get_czas_wyjazdu_min() << endl;
        }

        if (myKursy[nr_kursu - 1].czas_przyjazdu.godz > 9 && myKursy[nr_kursu - 1].czas_przyjazdu.godz < 24)
        {
            cout << "Czas przyjazdu pociagu: " << myKursy[nr_kursu - 1].czas_przyjazdu.godz;
        }
        else
        {
            cout << "Czas przyjazdu pociagu: 0" << myKursy[nr_kursu - 1].czas_przyjazdu.godz;
        }

        if (myKursy[nr_kursu - 1].czas_przyjazdu.min > 9 && myKursy[nr_kursu - 1].czas_przyjazdu.min < 60)
        {
            cout << ":" << myKursy[nr_kursu - 1].czas_przyjazdu.min << endl;
        }
        else
        {
            cout << ":0" << myKursy[nr_kursu - 1].czas_przyjazdu.min << endl;
        }
    }
    else
    {
        cout << "Nr. kursu: Brak." << endl;
        cout << "Czas wyjazdu pociagu: Brak." << endl;
        cout << "Czas przyjazdu pociagu: Brak." << endl;
    }

    if (getch())
    {
        system("cls");
        pokaz_menu();
    }
}