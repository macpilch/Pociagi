#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokaz_elementy_pociagow(void)
{
    int wybor = 0;

    cout << "1. Pokaz pociagi do wybrania.\n2. Dodaj nowy pociag.\n3. Usun pociag.\n4. Zapis pociagow do pliku.\n5. Powrot do menu.\n";
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
        zapisz_pociagi();
        break;
    case 5:
        system("cls");
        pokaz_menu();
        break;
    }
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
    pokaz_elementy_pociagow();
}

void wczytaj_pociagi(void)
{
    fstream plik_baza_pociagi;
    string tmpNazwa;
    int tmpPred = 0;
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
            myPociagi.clear();

            for (int i = 0; i < wielkosc; i++)
            {
                plik_baza_pociagi >> tmpNazwa;
                plik_baza_pociagi >> tmpPred;

                myPociagi.push_back(Pociag());
                myPociagi[i].set_pociag(tmpNazwa, tmpPred);
            }
        }
    }
    else
    {
        cout << "Brak pliku z baza danych pociagow!" << endl;
    }

    plik_baza_pociagi.close();
}

void pokaz_pociagi(void)
{
    for (unsigned int i = 0; i < myPociagi.size(); i++)
    {
        cout << "Nr." << i + 1 << " Nazwa: " << myPociagi[i].get_nazwa();
        cout << " Predkosc: " << myPociagi[i].get_predkosc() << endl;
    }

    cout << "\nPodaj numer pociagu, ktory chcesz wybrac: ";
    cin >> nr_pociagu;

    if (getch())
    {
        system("cls");
        pokaz_elementy_pociagow();
    }
}

void dodaj_pociag(void)
{
    string nazwa;
    int predkosc = 0;
    double ilosc = 0;

    cout << "Podaj nazwe pociagu ktora chcesz dodac: \n";
    cin >> nazwa;

    for (unsigned int i = 0; i < myPociagi.size(); i++)
    {
        if (nazwa == myPociagi[i].get_nazwa())
        {
            system("cls");
            cout << "Taka nazwa juz istnieje!\n\n";
            pokaz_elementy_pociagow();
        }
    }

    cout << "Podaj predkosc pociagu: \n";
    cin >> predkosc; // podanie predkosci w h

    myPociagi.push_back(Pociag());
    ilosc = myPociagi.size();
    myPociagi[ilosc - 1].set_pociag(nazwa, predkosc);

    system("cls");
    pokaz_elementy_pociagow();
}

void usun_pociag(void)
{
    unsigned int id = 0;

    cout << "Podaj ID pociagu, ktore chcesz usunac: \n";
    cin >> id;

    if (id > myPociagi.size())
    {
        cout << "Taki pociag nie istnieje!" << endl;
    }
    else
    {
        myPociagi.erase(myPociagi.begin() + id);
    }

    system("cls");
    pokaz_elementy_pociagow();
}