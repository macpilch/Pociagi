#include <string.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "../inc/miejsca.h"
#include "../inc/pociagi.h"
#include "../inc/tory.h"

using namespace std;

vector<Miejsce> myMiejsca;
vector<Pociag> myPociagi;
vector<Tor> myTory;

void pokaz_menu(void);
void pokaz_elementy_miejsc(void);
void pokaz_elementy_pociagow(void);
void pokaz_elementy_torow(void);
void pokaz_miejsca(void);
void dodaj_miejsce(void);
void usun_miejsce(void);
void zapisz_miejsce(void);
void wczytaj_miejsce(void);
void pokaz_pociagi(void);
void dodaj_pociag(void);
void usun_pociag(void);
void zapisz_pociagi(void);
void wczytaj_pociagi(void);
void pokaz_tory(void);
void dodaj_tor(void);
void usun_tor(void);

int main(void)
{
    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl
         << endl;

    wczytaj_miejsce();
    wczytaj_pociagi();
    pokaz_menu();
    return 0;
}

void pokaz_menu(void)
{
    int wybor = 0;

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

void pokaz_elementy_pociagow(void)
{
    int wybor = 0;

    cout << "1. Pokaz pociagi do wybrania.\n2. Dodaj nowy pociag.\n3. Usun pociag.\n4. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_pociagi();
        break;
    case 2:
        system("cls");
        dodaj_pociag();
        break;
    case 3:
        system("cls");
        usun_pociag();
        break;
    case 4:
        system("cls");
        pokaz_menu();
        break;
    }
}

void pokaz_elementy_torow(void)
{
    int wybor = 0;

    cout << "1. Pokaz tory do wybrania.\n2. Dodaj nowy tor.\n3. Usun tor.\n4. Powrot do menu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        system("cls");
        pokaz_tory();
        break;
    case 2:
        system("cls");
        dodaj_tor();
        break;
    case 3:
        system("cls");
        usun_tor();
        break;
    case 4:
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
    int tmpOdlg;
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
    pokaz_elementy_miejsc();
}

void pokaz_miejsca(void)
{
    for (unsigned int i = 0; i < myMiejsca.size(); i++)
    {
        cout << "Miejscowosc: " << myMiejsca[i].get_nazwa() << endl;
        cout << "Odleglosc: " << myMiejsca[i].get_odleglosc() << endl;
    }

    pokaz_elementy_miejsc();
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
            cout << "Taka nazwa juz istnieje!" << endl;
            break;
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

void zapisz_pociagi(void)
{
    fstream plik_baza_pociagi;
    int wielkosc = myPociagi.size();

    plik_baza_pociagi.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/pociagi", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_pociagi.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_pociagi << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_pociagi << myPociagi[i].get_nazwa() << endl;
            plik_baza_pociagi << myPociagi[i].get_predkosc() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych pociagow!" << endl;
    }

    plik_baza_pociagi.close();
    pokaz_elementy_miejsc();
}

void wczytaj_pociagi(void)
{
    fstream plik_baza_pociagi;
    string tmpNazwa;
    int tmpPred;
    int wielkosc = 0;

    plik_baza_pociagi.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/pociagi", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_pociagi.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_pociagi >> wielkosc;

        if (!wielkosc)
        {
            cout << "Baza danych pociagow pusta!";
        }
        else
        {
            myMiejsca.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_pociagi >> tmpNazwa;
                plik_baza_pociagi >> tmpPred;

                myMiejsca.push_back(Miejsce());
                myMiejsca[i].set_miejsce(tmpNazwa, tmpPred);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych pociagow!" << endl;
    }

    plik_baza_pociagi.close();
    pokaz_elementy_miejsc();
}

void pokaz_pociagi(void)
{
    for (unsigned int i = 0; i < myPociagi.size(); i++)
    {
        cout << "Nazwa: " << myPociagi[i].get_nazwa() << endl;
        cout << "Predkosc: " << myPociagi[i].get_predkosc() << endl;
    }

    pokaz_elementy_pociagow();
}

void dodaj_pociag(void)
{
    string nazwa;
    int predkosc = 0;
    int ilosc = 0;

    cout << "Podaj nazwe pociagu ktora chcesz dodac: \n";
    cin >> nazwa;

    cout << "Podaj predkosc pociagu: \n";
    cin >> predkosc;

    myPociagi.push_back(Pociag());
    ilosc = myPociagi.size();
    myPociagi[ilosc - 1].set_pociag_nazwa(nazwa);
    myPociagi[ilosc - 1].set_pociag_pred(predkosc);
    pokaz_elementy_pociagow();
}

void usun_pociag(void)
{
    int id = 0;

    cout << "Podaj ID pociagu, ktore chcesz usunac: \n";
    cin >> id;

    myPociagi.erase(myPociagi.begin() + id);
    pokaz_elementy_pociagow();
}

void pokaz_tory(void)
{
    for (unsigned int i = 0; i < myTory.size(); i++)
    {
        cout << "Poczatek: " << myTory[i].get_poczatek() << endl;
        cout << "Koniec: " << myTory[i].get_koniec() << endl;
    }

    pokaz_elementy_torow();
}

void dodaj_tor(void)
{
    int poczatek = 0;
    int ilosc = 0;

    cout << "Podaj poczatek toru ktory chcesz dodac: \n";
    cin >> poczatek;

    myTory.push_back(Tor());
    ilosc = myTory.size();
    myTory[ilosc].set_poczatek(poczatek);
    myTory[ilosc].set_dostepnosc(true);
    pokaz_elementy_torow();
}

void usun_tor(void)
{
    int id = 0;

    cout << "Podaj ID toru, ktore chcesz usunac: \n";
    cin >> id;

    myTory.erase(myTory.begin() + id);
    pokaz_elementy_torow();
}