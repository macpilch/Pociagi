/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: miejsca_funkcje.cpp
    Data: 09.03.2022
    Modyfikacja: 23.07.2022
*/

#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokazElementyMiejsc(VECM &mM) {
    cout << "MENU MIEJSC (wybierz odpowiednia opcje):" << endl << endl << "1. Pokaz miejsca do wybrania." << endl << "2. Dodaj nowe miejsce." << endl << "3. Usun miejsce." << endl << "4. Zapis miejsc do pliku." << endl << "5. Powrot do menu." << endl;

    switch(getch()) {
    case K_KLAW_1:
        system("cls");
        pokazMiejsca(mM);
        break;
    case K_KLAW_2:
        system("cls");
        dodajMiejsce(mM);
        break;
    case K_KLAW_3:
        system("cls");
        usunMiejsce(mM);
        break;
    case K_KLAW_4:
        system("cls");
        zapiszMiejsca(mM);
        break;
    case K_KLAW_5:
        system("cls");
        pokazMenu();
        break;
    default:
        system("cls");
        pokazElementyMiejsc(mM);
        break;
    }
}

void zapiszMiejsca(VECM &mM) {
    fstream plikBazaMiejsc;
    int wielkosc = mM.size();

    plikBazaMiejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in | ios::trunc);

    if(plikBazaMiejsc.is_open()) {
        cout << "Plik otwarto!" << endl << "Dane zostaly pomyslnie zapisane." << endl << endl;

        plikBazaMiejsc << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plikBazaMiejsc << mM[i].getNazwa() << endl;
            plikBazaMiejsc << mM[i].getOdleglosc() << endl;
        }
    } else {
        cout << "Brak pliku z baza danych miejsc!" << endl << endl;
    }

    plikBazaMiejsc.close();
    pokazElementyMiejsc(mM);
}

void wczytajMiejsca(VECM &mM) {
    fstream plikBazaMiejsc;
    string tmpNazwa;
    double tmpOdlg = 0;
    int wielkosc = 0;

    plikBazaMiejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in);

    if(plikBazaMiejsc.is_open()) {
        cout << "Plik otwarto!" << endl;

        plikBazaMiejsc >> wielkosc;

        if(!wielkosc) {
            cout << "Baza danych miejsc pusta!" << endl;
        } else {
            mM.clear();

            for(int i = 0; i < wielkosc; i++) {
                plikBazaMiejsc >> tmpNazwa;
                plikBazaMiejsc >> tmpOdlg;

                mM.push_back(Miejsce());
                mM[i].setMiejsce(tmpNazwa, tmpOdlg);
            }
        }
    } else {
        cout << "Brak pliku z baza danych miejsc!" << endl;
    }

    plikBazaMiejsc.close();
}

void pokazMiejsca(VECM &mM) {
    cout << "Dostepne miejsca: " << endl;
    
    for(UINT i = 0; i < mM.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << mM[i].getNazwa();
        cout << " Odleglosc: " << mM[i].getOdleglosc() << " km." << endl;
    }

    cout << endl << "Nacisnij ESC aby powrocic do menu.";

    if(getch() == K_ESC) {
        system("cls");
        pokazElementyMiejsc(mM);
    } else {
        system("cls");
        pokazMiejsca(mM);
    }
}

void dodajMiejsce(VECM &mM) {
    string nazwa;
    double odlg = 0;
    int ilosc = 0;

    if(mM.size() == MAX_MIEJSC) {
        system("cls");
        cout << "Osiagnieto limit miejsc (20)!" << endl << endl;
        pokazElementyMiejsc(mM);
    }

    cout << "Podaj nazwe miejscowosci ktora chcesz dodac (Wolnych miejsc: " << (MAX_MIEJSC - mM.size()) << "): " << endl;
    cin >> nazwa;

    for(UINT i = 0; i < mM.size(); i++) {
        if(nazwa == mM[i].getNazwa()) {
            system("cls");
            cout << "Taka miejscowosc juz istnieje!" << endl << endl;
            pokazElementyMiejsc(mM);
        }
    }

    cout << "Podaj odleglosc od tej miejscowosci: " << endl;
    cin >> odlg;

    mM.push_back(Miejsce());
    ilosc = mM.size();
    mM[ilosc - 1].setMiejsce(nazwa, odlg);

    system("cls");
    pokazElementyMiejsc(mM);
}

void usunMiejsce(VECM &mM) {
    UINT id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: " << endl;
    cin >> id;

    if(id > mM.size()) {
        system("cls");
        cout << "Takie miejsce nie istnieje!" << endl << endl;
        pokazElementyMiejsc(mM);
    } else {
        mM.erase(mM.begin() + id);
        system("cls");
        pokazElementyMiejsc(mM);
    }
}