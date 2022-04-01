#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokaz_elementy_miejsc(vector<Miejsce> &mm)
{
    int wybor = 0;

    cout << "MENU MIEJSC (wybierz odpowiednia opcje):\n\n1. Pokaz miejsca do wybrania.\n2. Dodaj nowe miejsce.\n3. Usun miejsce.\n4. Zapis miejsc do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_miejsca(mm);
        break;
    case 2:
        system("cls");
        dodaj_miejsce(mm);
        break;
    case 3:
        system("cls");
        usun_miejsce(mm);
        break;
    case 4:
        system("cls");
        zapisz_miejsce(mm);
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
}

void zapisz_miejsce(vector<Miejsce> &mm)
{
    fstream plik_baza_miejsc;
    int wielkosc = mm.size();

    plik_baza_miejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_miejsc.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_miejsc << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_miejsc << mm[i].get_nazwa() << endl;
            plik_baza_miejsc << mm[i].get_odleglosc() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych miejsc!" << endl;
    }

    plik_baza_miejsc.close();
    pokaz_elementy_miejsc(mm);
}

void wczytaj_miejsce(vector<Miejsce> &mm)
{
    fstream plik_baza_miejsc;
    string tmpNazwa;
    double tmpOdlg = 0;
    int wielkosc = 0;

    plik_baza_miejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in);

    if (plik_baza_miejsc.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_miejsc >> wielkosc;

        if (!wielkosc)
        {
            cout << "Baza danych miejsc pusta!";
        }
        else
        {
            mm.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_miejsc >> tmpNazwa;
                plik_baza_miejsc >> tmpOdlg;

                mm.push_back(Miejsce());
                mm[i].set_miejsce(tmpNazwa, tmpOdlg);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych miejsc!" << endl;
    }

    plik_baza_miejsc.close();
}

void pokaz_miejsca(vector<Miejsce> &mm)
{
    for (unsigned int i = 0; i < mm.size(); i++)
    {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << mm[i].get_nazwa();
        cout << " Odleglosc: " << mm[i].get_odleglosc() << " km." << endl;
    }

    if (getch())
    {
        system("cls");
        pokaz_elementy_miejsc(mm);
    }
}

void dodaj_miejsce(vector<Miejsce> &mm)
{
    string nazwa;
    double odlg = 0;
    int ilosc = 0;

    cout << "Podaj nazwe miejscowosci ktora chcesz dodac: \n";
    cin >> nazwa;

    for (unsigned int i = 0; i < mm.size(); i++)
    {
        if (nazwa == mm[i].get_nazwa())
        {
            system("cls");
            cout << "Taka nazwa juz istnieje!\n\n";
            pokaz_elementy_miejsc(mm);
        }
    }

    cout << "Podaj odleglosc od tej miejscowosci: \n";
    cin >> odlg;

    mm.push_back(Miejsce());
    ilosc = mm.size();
    mm[ilosc - 1].set_miejsce(nazwa, odlg);

    system("cls");
    pokaz_elementy_miejsc(mm);
}

void usun_miejsce(vector<Miejsce> &mm)
{
    unsigned int id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: \n";
    cin >> id;

    if (id > mm.size())
    {
        cout << "Takie miejsce nie istnieje!" << endl;
    }
    else
    {
        mm.erase(mm.begin() + id);
    }

    system("cls");
    pokaz_elementy_miejsc(mm);
}