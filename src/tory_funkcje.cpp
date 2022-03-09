#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

vector<Tor> myTory;

void pokaz_elementy_torow(void)
{
    int wybor = 0;

    cout << "1. Pokaz tory do wybrania.\n2. Dodaj nowy tor.\n3. Usun tor.\n4. Zapis torow do pliku.\n5. Powrot do menu.\n";
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
        zapisz_tory();
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
}

void zapisz_tory(void)
{
    fstream plik_baza_torow;
    int wielkosc = myTory.size();

    plik_baza_torow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/tory", fstream::out | fstream::in | ios::trunc);

    if (plik_baza_torow.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_torow << wielkosc << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            plik_baza_torow << myTory[i].get_numer() << endl;
            plik_baza_torow << myTory[i].get_poczatek() << endl;
            plik_baza_torow << myTory[i].get_koniec() << endl;
        }
    }
    else
    {
        cout << "Brak pliku z baza danych torow!" << endl;
    }

    plik_baza_torow.close();
    pokaz_elementy_torow();
}

void wczytaj_tory(void)
{
    fstream plik_baza_torow;
    int tmpNum = 0;
    int tmpPocz = 0;
    int tmpKon = 0;
    int wielkosc = 0;

    plik_baza_torow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/tory", fstream::out | fstream::in);

    if (plik_baza_torow.is_open())
    {
        cout << "Plik otwarto!" << endl;

        plik_baza_torow >> wielkosc;

        if (!wielkosc)
        {
            cout << "Baza danych jest pusta!" << endl;
        }
        else
        {
            myTory.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_torow >> tmpNum;
                plik_baza_torow >> tmpPocz;
                plik_baza_torow >> tmpKon;

                myTory.push_back(Tor());
                myTory[i].set_tor(tmpNum, tmpPocz, tmpKon);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych torow!" << endl;
    }

    plik_baza_torow.close();
}

void pokaz_tory(void)
{
    for (unsigned int i = 0; i < myTory.size(); i++)
    {
        cout << "Numer: " << myTory[i].get_numer() << endl;
        cout << "Poczatek: " << myTory[i].get_poczatek() << endl;
        cout << "Koniec: " << myTory[i].get_koniec() << endl;
    }

    if (getch())
    {
        system("cls");
        pokaz_elementy_torow();
    }
}

void dodaj_tor(void)
{
    int numer = 0;
    int poczatek = 0;
    int koniec = 0;
    int ilosc = 0;

    cout << "Podaj numer toru ktory chcesz dodac: \n";
    cin >> numer;

    cout << "Podaj poczatek toru ktory chcesz dodac: \n";
    cin >> poczatek;

    cout << "Podaj koniec toru ktory chcesz dodac: \n";
    cin >> koniec;

    myTory.push_back(Tor());
    ilosc = myTory.size();
    myTory[ilosc - 1].set_tor(numer, poczatek, koniec);

    system("cls");
    pokaz_elementy_torow();
}

void usun_tor(void)
{
    unsigned int id = 0;

    cout << "Podaj ID toru, ktory chcesz usunac: \n";
    cin >> id;

    if (id > myTory.size())
    {
        cout << "Taki tor nie istnieje!" << endl;
    }
    else
    {
        myTory.erase(myTory.begin() + id);
    }

    system("cls");
    pokaz_elementy_torow();
}