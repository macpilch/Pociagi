#include <iostream>
#include "../inc/kursy.h"
#include "../inc/funkcje.h"

using namespace std;

void pokaz_elementy_kursow(vector<Kurs> &mk)
{
    int wybor = 0;

    cout << "MENU KURSOW (wybierz odpowiednia opcje):\n\n1. Pokaz kursy do wybrania.\n2. Dodaj nowy kurs.\n3. Usun kurs.\n4. Zapis kursow do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_kursy(mk);
        break;
    case 2:
        system("cls");
        dodaj_kurs(mk);
        break;
    case 3:
        system("cls");
        usun_kurs(mk);
        break;
    case 4:
        system("cls");
        zapisz_kursy(mk);
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
}

void zapisz_kursy(vector<Kurs> &mk)
{
    fstream plik_baza_kursow;
    int wielkosc = mk.size();

    plik_baza_kursow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/kursy", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_kursow.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_kursow << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_kursow << mk[i].get_czas_wyjazdu_godz() << endl;
            plik_baza_kursow << mk[i].get_czas_wyjazdu_min() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych kursow!" << endl;
    }

    plik_baza_kursow.close();
    pokaz_elementy_kursow(mk);
}

void wczytaj_kursy(vector<Kurs> &mk)
{
    fstream plik_baza_kursow;
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
            mk.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_kursow >> tmpGodz;
                plik_baza_kursow >> tmpMin;

                mk.push_back(Kurs());
                mk[i].set_kurs(tmpGodz, tmpMin);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych kursow!" << endl;
    }

    plik_baza_kursow.close();
}

void pokaz_kursy(vector<Kurs> &mk)
{
    for (unsigned int i = 0; i < mk.size(); i++)
    {
        cout << "Nr. " << i + 1;

        if (mk[i].get_czas_wyjazdu_godz() > 9 && mk[i].get_czas_wyjazdu_godz() < 24)
        {
            cout << " Czas wyjazdu: " << mk[i].get_czas_wyjazdu_godz();
        }
        else
        {
            cout << " Czas wyjazdu: 0" << mk[i].get_czas_wyjazdu_godz();
        }

        if (mk[i].get_czas_wyjazdu_min() > 9 && mk[i].get_czas_wyjazdu_min() < 59)
        {
            cout << ":" << mk[i].get_czas_wyjazdu_min() << "." << endl;
        }
        else
        {
            cout << ":0" << mk[i].get_czas_wyjazdu_min() << "." << endl;
        }
    }

    if (getch())
    {
        system("cls");
        pokaz_elementy_kursow(mk);
    }
}

void dodaj_kurs(vector<Kurs> &mk)
{
    int godzina = 0;
    int minuty = 0;
    int ilosc = 0;

    cout << "Podaj godzine o ktorej zacznie sie kurs: \n";
    cin >> godzina;

    cout << "Podaj liczbe minut o ktorej zacznie sie kurs: \n";
    cin >> minuty;

    mk.push_back(Kurs());
    ilosc = mk.size();
    mk[ilosc - 1].set_kurs(godzina, minuty);

    system("cls");
    pokaz_elementy_kursow(mk);
}

void usun_kurs(vector<Kurs> &mk)
{
    unsigned int id = 0;

    cout << "Podaj ID kursu, ktory chcesz usunac: \n";
    cin >> id;

    if (id > mk.size())
    {
        cout << "Taki kurs nie istnieje!" << endl;
    }
    else
    {
        mk.erase(mk.begin() + id);
    }

    system("cls");
    pokaz_elementy_kursow(mk);
}