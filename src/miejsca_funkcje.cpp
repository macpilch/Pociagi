#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

vector<Miejsce> myMiejsca;

void pokaz_elementy_miejsc(void)
{
    int wybor = 0;

    cout << "1. Pokaz miejsca do wybrania.\n2. Dodaj nowe miejsce.\n3. Usun miejsce.\n4. Zapis miejsc do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_miejsca();
        break;
    case 2:
        system("cls");
        dodaj_miejsce();
        break;
    case 3:
        system("cls");
        usun_miejsce();
        break;
    case 4:
        system("cls");
        zapisz_miejsce();
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
}

void zapisz_miejsce(void)
{
    fstream plik_baza_miejsc;
    int wielkosc = myMiejsca.size();

    plik_baza_miejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_miejsc.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_miejsc << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_miejsc << myMiejsca[i].get_nazwa() << endl;
            plik_baza_miejsc << myMiejsca[i].get_odleglosc() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych miejsc!" << endl;
    }

    plik_baza_miejsc.close();
    pokaz_elementy_miejsc();
}

void wczytaj_miejsce(void)
{
    fstream plik_baza_miejsc;
    string tmpNazwa;
    int tmpOdlg = 0;
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
            myMiejsca.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_miejsc >> tmpNazwa;
                plik_baza_miejsc >> tmpOdlg;

                myMiejsca.push_back(Miejsce());
                myMiejsca[i].set_miejsce(tmpNazwa, tmpOdlg);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych miejsc!" << endl;
    }

    plik_baza_miejsc.close();
}

void pokaz_miejsca(void)
{
    for (unsigned int i = 0; i < myMiejsca.size(); i++)
    {
        cout << "Miejscowosc: " << myMiejsca[i].get_nazwa() << endl;
        cout << "Odleglosc: " << myMiejsca[i].get_odleglosc() << endl;
    }

    if (getch())
    {
        system("cls");
        pokaz_elementy_miejsc();
    }
}

void dodaj_miejsce(void)
{
    string nazwa;
    int odlg = 0;
    int ilosc = 0;

    cout << "Podaj nazwe miejscowosci ktora chcesz dodac: \n";
    cin >> nazwa;

    for (unsigned int i = 0; i < myMiejsca.size(); i++)
    {
        if (nazwa == myMiejsca[i].get_nazwa())
        {
            system("cls");
            cout << "Taka nazwa juz istnieje!\n\n";
            pokaz_elementy_miejsc();
        }
    }

    cout << "Podaj odleglosc od tej miejscowosci: \n";
    cin >> odlg;

    myMiejsca.push_back(Miejsce());
    ilosc = myMiejsca.size();
    myMiejsca[ilosc - 1].set_miejsce(nazwa, odlg);

    system("cls");
    pokaz_elementy_miejsc();
}

void usun_miejsce(void)
{
    unsigned int id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: \n";
    cin >> id;

    if (id > myMiejsca.size())
    {
        cout << "Takie miejsce nie istnieje!" << endl;
    }
    else
    {
        myMiejsca.erase(myMiejsca.begin() + id);
    }

    system("cls");
    pokaz_elementy_miejsc();
}