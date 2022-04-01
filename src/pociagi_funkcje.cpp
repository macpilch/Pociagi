#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokaz_elementy_pociagow(vector<Pociag> &mp)
{
    int wybor = 0;

    cout << "MENU POCIAGOW (wybierz odpowiednia opcje):\n\n1. Pokaz pociagi do wybrania.\n2. Dodaj nowy pociag.\n3. Usun pociag.\n4. Zapis pociagow do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_pociagi(mp);
        break;
    case 2:
        system("cls");
        dodaj_pociag(mp);
        break;
    case 3:
        system("cls");
        usun_pociag(mp);
        break;
    case 4:
        system("cls");
        zapisz_pociagi(mp);
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
}

void zapisz_pociagi(vector<Pociag> &mp)
{
    fstream plik_baza_pociagi;
    int wielkosc = mp.size();

    plik_baza_pociagi.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/pociagi", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_pociagi.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_pociagi << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_pociagi << mp[i].get_nazwa() << endl;
            plik_baza_pociagi << mp[i].get_predkosc() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych pociagow!" << endl;
    }

    plik_baza_pociagi.close();
    pokaz_elementy_pociagow(mp);
}

void wczytaj_pociagi(vector<Pociag> &mp)
{
    fstream plik_baza_pociagi;
    string tmpNazwa;
    double tmpPred = 0;
    int wielkosc = 0;

    plik_baza_pociagi.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/pociagi", fstream::out | fstream::in);

    if (plik_baza_pociagi.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_pociagi >> wielkosc;

        if (!wielkosc)
        {
            cout << "Baza danych pociagow pusta!" << endl;
        }
        else
        {
            mp.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_pociagi >> tmpNazwa;
                plik_baza_pociagi >> tmpPred;

                mp.push_back(Pociag());
                mp[i].set_pociag(tmpNazwa, tmpPred);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych pociagow!" << endl;
    }

    plik_baza_pociagi.close();
}

void pokaz_pociagi(vector<Pociag> &mp)
{
    for (unsigned int i = 0; i < mp.size(); i++)
    {
        cout << "Nr. " << i + 1 << " Nazwa: " << mp[i].get_nazwa();
        cout << " Predkosc: " << mp[i].get_predkosc() << " km/h." << endl;
    }

    if (getch())
    {
        system("cls");
        pokaz_elementy_pociagow(mp);
    }
}

void dodaj_pociag(vector<Pociag> &mp)
{
    string nazwa;
    double predkosc = 0;
    int ilosc = 0;

    cout << "Podaj nazwe pociagu ktora chcesz dodac: \n";
    cin >> nazwa;

    for (unsigned int i = 0; i < mp.size(); i++)
    {
        if (nazwa == mp[i].get_nazwa())
        {
            system("cls");
            cout << "Taka nazwa juz istnieje!\n\n";
            pokaz_elementy_pociagow(mp);
        }
    }

    cout << "Podaj predkosc pociagu: \n";
    cin >> predkosc; // podanie predkosci w h

    mp.push_back(Pociag());
    ilosc = mp.size();
    mp[ilosc - 1].set_pociag(nazwa, predkosc);

    system("cls");
    pokaz_elementy_pociagow(mp);
}

void usun_pociag(vector<Pociag> &mp)
{
    unsigned int id = 0;

    cout << "Podaj ID pociagu, ktore chcesz usunac: \n";
    cin >> id;

    if (id > mp.size())
    {
        cout << "Taki pociag nie istnieje!" << endl;
    }
    else
    {
        mp.erase(mp.begin() + id);
    }

    system("cls");
    pokaz_elementy_pociagow(mp);
}