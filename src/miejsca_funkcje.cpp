/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: miejsca_funkcje.cpp
    Data: 09.03.2022
    Modyfikacja: 15.07.2022
*/

#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokazElementyMiejsc(vecM &mM) {
    int wybor = 0;

    cout << "MENU MIEJSC (wybierz odpowiednia opcje):\n\n1. Pokaz miejsca do wybrania.\n2. Dodaj nowe miejsce.\n3. Usun miejsce.\n4. Zapis miejsc do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        system("cls");
        pokazMiejsca(mM);
        break;
    case 2:
        system("cls");
        dodajMiejsce(mM);
        break;
    case 3:
        system("cls");
        usunMiejsce(mM);
        break;
    case 4:
        system("cls");
        zapiszMiejsce(mM);
        break;
    case 5:
        system("cls");
        pokazMenu();
        break;
    default:
        system("cls");
        pokazElementyMiejsc(mM);
        break;
    }
}

void zapiszMiejsce(vecM &mM) {
    fstream plikBazaMiejsc;
    int wielkosc = mM.size();

    plikBazaMiejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in | ios::trunc);

    if(plikBazaMiejsc.is_open()) {
        cout << "Plik otwarto!\nDane zostaly pomyslnie zapisane.\n\n";

        plikBazaMiejsc << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plikBazaMiejsc << mM[i].getNazwa() << endl;
            plikBazaMiejsc << mM[i].getOdleglosc() << endl;
        }
    } else {
        cout << "Brak pliku z baza danych miejsc!\n\n";
    }

    plikBazaMiejsc.close();
    pokazElementyMiejsc(mM);
}

void wczytajMiejsce(vecM &mM) {
    fstream plikBazaMiejsc;
    string tmpNazwa;
    double tmpOdlg = 0;
    int wielkosc = 0;

    plikBazaMiejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in);

    if(plikBazaMiejsc.is_open()) {
        cout << "Plik otwarto!\n";

        plikBazaMiejsc >> wielkosc;

        if(!wielkosc) {
            cout << "Baza danych miejsc pusta!\n";
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
        cout << "Brak pliku z baza danych miejsc!\n";
    }

    plikBazaMiejsc.close();
}

void pokazMiejsca(vecM &mM) {
    cout << "Dostepne miejsca: \n";
    
    for(uInt i = 0; i < mM.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << mM[i].getNazwa();
        cout << " Odleglosc: " << mM[i].getOdleglosc() << " km.\n";
    }

    cout << "\nNacisnij ESC aby powrocic do menu.";

    if(getch() == K_ESC) {
        system("cls");
        pokazElementyMiejsc(mM);
    } else {
        system("cls");
        pokazMiejsca(mM);
    }
}

void dodajMiejsce(vecM &mM) {
    string nazwa;
    double odlg = 0;
    int ilosc = 0;

    if(mM.size() == MAX_MIEJSC) {
        system("cls");
        cout << "Osiagnieto limit miejsc (20)!\n\n";
        pokazElementyMiejsc(mM);
    }

    cout << "Podaj nazwe miejscowosci ktora chcesz dodac (Wolnych miejsc: " << (MAX_MIEJSC - mM.size()) << "): \n";
    cin >> nazwa;

    for(uInt i = 0; i < mM.size(); i++) {
        if(nazwa == mM[i].getNazwa()) {
            system("cls");
            cout << "Taka miejscowosc juz istnieje!\n\n";
            pokazElementyMiejsc(mM);
        }
    }

    cout << "Podaj odleglosc od tej miejscowosci: \n";
    cin >> odlg;

    mM.push_back(Miejsce());
    ilosc = mM.size();
    mM[ilosc - 1].setMiejsce(nazwa, odlg);

    system("cls");
    pokazElementyMiejsc(mM);
}

void usunMiejsce(vecM &mM) {
    uInt id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: \n";
    cin >> id;

    if(id > mM.size()) {
        system("cls");
        cout << "Takie miejsce nie istnieje!\n\n";
        pokazElementyMiejsc(mM);
    } else {
        mM.erase(mM.begin() + id);
        system("cls");
        pokazElementyMiejsc(mM);
    }
}