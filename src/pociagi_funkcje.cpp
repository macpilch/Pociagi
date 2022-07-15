/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: pociagi_funkcje.cpp
    Data: 09.03.2022
    Modyfikacja: 15.07.2022
*/

#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

void pokazElementyPociagow(vecP &mP) {
    int wybor = 0;

    cout << "MENU POCIAGOW (wybierz odpowiednia opcje):\n\n1. Pokaz pociagi do wybrania.\n2. Dodaj nowy pociag.\n3. Usun pociag.\n4. Zapis pociagow do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        system("cls");
        pokazPociagi(mP);
        break;
    case 2:
        system("cls");
        dodajPociag(mP);
        break;
    case 3:
        system("cls");
        usunPociag(mP);
        break;
    case 4:
        system("cls");
        zapiszPociagi(mP);
        break;
    case 5:
        system("cls");
        pokazMenu();
        break;
    default:
        system("cls");
        pokazElementyPociagow(mP);
        break;
    }
}

void zapiszPociagi(vecP &mP) {
    fstream plikBazaPociagi;
    int wielkosc = mP.size();

    plikBazaPociagi.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/pociagi", fstream::out | fstream::in | ios::trunc);

    if(plikBazaPociagi.is_open()) {
        cout << "Plik otwarto!\nDane zostaly pomyslnie zapisane.\n\n";

        plikBazaPociagi << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plikBazaPociagi << mP[i].getNazwa() << endl;
            plikBazaPociagi << mP[i].getPredkosc() << endl;
        }
    } else {
        cout << "Brak pliku z baza danych pociagow!\n\n";
    }

    plikBazaPociagi.close();
    pokazElementyPociagow(mP);
}

void wczytajPociagi(vecP &mP) {
    fstream plikBazaPociagi;
    string tmpNazwa;
    double tmpPred = 0;
    int wielkosc = 0;

    plikBazaPociagi.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/pociagi", fstream::out | fstream::in);

    if(plikBazaPociagi.is_open()) {
        cout << "Plik otwarto!\n";

        plikBazaPociagi >> wielkosc;

        if(!wielkosc) {
            cout << "Baza danych pociagow pusta!\n";
        } else {
            mP.clear();

            for(int i = 0; i < wielkosc; i++) {
                plikBazaPociagi >> tmpNazwa;
                plikBazaPociagi >> tmpPred;

                mP.push_back(Pociag());
                mP[i].setPociag(tmpNazwa, tmpPred);
            }
        }
    } else {
        cout << "Brak pliku z baza danych pociagow!\n";
    }

    plikBazaPociagi.close();
}

void pokazPociagi(vecP &mP) {
    cout << "Dostepne pociagi: \n";
    
    for(uInt i = 0; i < mP.size(); i++) {
        cout << "Nr. " << i + 1 << " Nazwa: " << mP[i].getNazwa();
        cout << " Predkosc: " << mP[i].getPredkosc() << " km/h.\n";
    }

    cout << "\nNacisnij dowolny przycisk aby powrocic do menu.";

    if(getch()) {
        system("cls");
        pokazElementyPociagow(mP);
    }
}

void dodajPociag(vecP &mP) {
    string nazwa;
    double predkosc = 0;
    int ilosc = 0;

    if(mP.size() == MAX_POCIAGOW) {
        system("cls");
        cout << "Osiagnieto limit pociagow (15)!\n\n";
        pokazElementyPociagow(mP);
    }

    cout << "Podaj nazwe pociagu ktora chcesz dodac (Wolnych miejsc: " << (MAX_POCIAGOW - mP.size()) << "): \n";
    cin >> nazwa;

    for(uInt i = 0; i < mP.size(); i++) {
        if(nazwa == mP[i].getNazwa()) {
            system("cls");
            cout << "Taki pociag juz istnieje!\n\n";
            pokazElementyPociagow(mP);
        }
    }

    cout << "Podaj predkosc pociagu: \n";
    cin >> predkosc; // podanie predkosci w h

    mP.push_back(Pociag());
    ilosc = mP.size();
    mP[ilosc - 1].setPociag(nazwa, predkosc);

    system("cls");
    pokazElementyPociagow(mP);
}

void usunPociag(vecP &mP) {
    uInt id = 0;

    cout << "Podaj ID pociagu, ktore chcesz usunac: \n";
    cin >> id;

    if(id > mP.size()) {
        system("cls");
        cout << "Taki pociag nie istnieje!\n\n";
        pokazElementyPociagow(mP);
    } else {
        mP.erase(mP.begin() + id);
        system("cls");
        pokazElementyPociagow(mP);
    }
}