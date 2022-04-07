#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokazElementyMiejsc(vector<Miejsce> &mM) {
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
    }
}

void zapiszMiejsce(vector<Miejsce> &mM) {
    fstream plikBazaMiejsc;
    int wielkosc = mM.size();

    plikBazaMiejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in | ios::trunc);

    if(plikBazaMiejsc.is_open()) {
        cout << "Plik otwarto!" << endl;

        plikBazaMiejsc << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plikBazaMiejsc << mM[i].getNazwa() << endl;
            plikBazaMiejsc << mM[i].getOdleglosc() << endl;
        }
    } else {
        cout << "Brak pliku z baza danych miejsc!" << endl;
    }

    plikBazaMiejsc.close();
    pokazElementyMiejsc(mM);
}

void wczytajMiejsce(vector<Miejsce> &mM) {
    fstream plikBazaMiejsc;
    string tmpNazwa;
    double tmpOdlg = 0;
    int wielkosc = 0;

    plikBazaMiejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in);

    if(plikBazaMiejsc.is_open()) {
        cout << "Plik otwarto!" << endl;

        plikBazaMiejsc >> wielkosc;

        if(!wielkosc) {
            cout << "Baza danych miejsc pusta!";
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

void pokazMiejsca(vector<Miejsce> &mM) {
    cout << "Dostepne miejsca: " << endl;
    
    for(unsigned int i = 0; i < mM.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << mM[i].getNazwa();
        cout << " Odleglosc: " << mM[i].getOdleglosc() << " km." << endl;
    }

    if(getch()) {
        system("cls");
        pokazElementyMiejsc(mM);
    }
}

void dodajMiejsce(vector<Miejsce> &mM) {
    string nazwa;
    double odlg = 0;
    int ilosc = 0;

    cout << "Podaj nazwe miejscowosci ktora chcesz dodac: \n";
    cin >> nazwa;

    for(unsigned int i = 0; i < mM.size(); i++) {
        if(nazwa == mM[i].getNazwa()) {
            system("cls");
            cout << "Taka nazwa juz istnieje!\n\n";
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

void usunMiejsce(vector<Miejsce> &mM) {
    unsigned int id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: \n";
    cin >> id;

    if(id > mM.size()) {
        cout << "Takie miejsce nie istnieje!" << endl;
    } else {
        mM.erase(mM.begin() + id);
    }

    system("cls");
    pokazElementyMiejsc(mM);
}