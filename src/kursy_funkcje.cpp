#include <iostream>
#include "../inc/kursy.h"
#include "../inc/funkcje.h"

using namespace std;

void pokaz_elementy_kursow(void)
{
    int wybor = 0;

    cout << "1. Pokaz kursy do wybrania.\n2. Dodaj nowy kurs.\n3. Usun kurs.\n4. Zapis kursow do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_kursy();
        break;
    case 2:
        system("cls");
        dodaj_kurs();
        break;
    case 3:
        system("cls");
        usun_kurs();
        break;
    case 4:
        system("cls");
        zapisz_kursy();
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
}

void zapisz_kursy(void)
{
    fstream plik_baza_kursow;
    int wielkosc = myKursy.size();

    plik_baza_kursow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/kursy", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_kursow.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_kursow << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_kursow << myKursy[i].get_numer() << endl;
            plik_baza_kursow << myKursy[i].get_czas_wyjazdu_godz() << endl;
            plik_baza_kursow << myKursy[i].get_czas_wyjazdu_min() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych kursow!" << endl;
    }

    plik_baza_kursow.close();
    pokaz_elementy_kursow();
}

void wczytaj_kursy(void)
{
    fstream plik_baza_kursow;
    int tmpNum = 0;
    int tmpGodz = 0;
    int tmpMin = 0;
    int wielkosc = 0;

    plik_baza_kursow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/kursy", fstream::out | fstream::in);

    if (plik_baza_kursow.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_kursow >> wielkosc;

        if (!wielkosc)
        {
            cout << "Baza danych jest pusta!" << endl;
        }
        else
        {
            myKursy.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_kursow >> tmpNum;
                plik_baza_kursow >> tmpGodz;
                plik_baza_kursow >> tmpMin;

                myKursy.push_back(Kurs());
                myKursy[i].set_kurs(tmpNum, tmpGodz, tmpMin);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych kursow!" << endl;
    }

    plik_baza_kursow.close();
}

void pokaz_kursy(void)
{
    for (unsigned int i = 0; i < myKursy.size(); i++)
    {
        cout << "Nr. " << myKursy[i].get_numer();
        cout << " Czas wyjazdu: " << myKursy[i].get_czas_wyjazdu_godz();
        cout << ":" << myKursy[i].get_czas_wyjazdu_min() << endl;
    }

    cout << "\nPodaj numer kursu, ktory chcesz wybrac: ";
    cin >> nr_kursu;

    myKursy[nr_kursu - 1].obliczanie_czasu(nr_miejsca, nr_kursu);

    if (getch())
    {
        system("cls");
        pokaz_elementy_kursow();
    }
}

void dodaj_kurs(void)
{
    int numer = 0;
    int godzina = 0;
    int minuty = 0;
    int ilosc = 0;

    cout << "Podaj numer kursu ktory chcesz dodac: \n";
    cin >> numer;

    cout << "Podaj godzine o ktorej zacznie sie kurs: \n";
    cin >> godzina;

    cout << "Podaj liczbe minut o ktorej zacznie sie kurs: \n";
    cin >> minuty;

    myKursy.push_back(Kurs());
    ilosc = myKursy.size();
    myKursy[ilosc - 1].set_kurs(numer, godzina, minuty);

    system("cls");
    pokaz_elementy_kursow();
}

void usun_kurs(void)
{
    unsigned int id = 0;

    cout << "Podaj ID kursu, ktory chcesz usunac: \n";
    cin >> id;

    if (id > myKursy.size())
    {
        cout << "Taki kurs nie istnieje!" << endl;
    }
    else
    {
        myKursy.erase(myKursy.begin() + id);
    }

    system("cls");
    pokaz_elementy_kursow();
}