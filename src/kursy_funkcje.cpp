#include <iostream>
#include "../inc/kursy.h"
#include "../inc/funkcje.h"

using namespace std;

void pokazElementyKursow(vector<Kurs> &mK) {
    int wybor = 0;

    cout << "MENU KURSOW (wybierz odpowiednia opcje):\n\n1. Pokaz kursy do wybrania.\n2. Dodaj nowy kurs.\n3. Usun kurs.\n4. Zapis kursow do pliku.\n5. Powrot do menu.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        system("cls");
        pokazKursy(mK);
        break;
    case 2:
        system("cls");
        dodajKurs(mK);
        break;
    case 3:
        system("cls");
        usunKurs(mK);
        break;
    case 4:
        system("cls");
        zapiszKursy(mK);
        break;
    case 5:
        system("cls");
        pokazMenu();
        break;
    }
}

void zapiszKursy(vector<Kurs> &mK) {
    fstream plikBazaKursow;
    int wielkosc = mK.size();

    plikBazaKursow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/kursy", fstream::out | fstream::in | ios::trunc);

    if(plikBazaKursow.is_open()) {
        cout << "Plik otwarto!" << endl;

        plikBazaKursow << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plikBazaKursow << mK[i].getCzasWyjazduGodz() << endl;
            plikBazaKursow << mK[i].getCzasWyjazduMin() << endl;
        }
    } else {
        cout << "Brak pliku z baza danych kursow!" << endl;
    }

    plikBazaKursow.close();
    pokazElementyKursow(mK);
}

void wczytajKursy(vector<Kurs> &mK) {
    fstream plikBazaKursow;
    int tmpGodz = 0;
    int tmpMin = 0;
    int wielkosc = 0;

    plikBazaKursow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/kursy", fstream::out | fstream::in);

    if(plikBazaKursow.is_open()) {
        cout << "Plik otwarto!" << endl;

        plikBazaKursow >> wielkosc;

        if(!wielkosc) {
            cout << "Baza danych jest pusta!" << endl;
        } else {
            mK.clear();

            for(int i = 0; i < wielkosc; i++) {
                plikBazaKursow >> tmpGodz;
                plikBazaKursow >> tmpMin;

                mK.push_back(Kurs());
                mK[i].setKurs(tmpGodz, tmpMin);
            }
        }
    } else {
        cout << "Brak pliku z baza danych kursow!" << endl;
    }

    plikBazaKursow.close();
}

void pokazKursy(vector<Kurs> &mK) {
    cout << "Dostepne kursy: " << endl;
    
    for(unsigned int i = 0; i < mK.size(); i++) {
        cout << "Nr. " << i + 1;

        if(mK[i].getCzasWyjazduGodz() > 9 && mK[i].getCzasWyjazduGodz() < 24) {
            cout << " Czas wyjazdu: " << mK[i].getCzasWyjazduGodz();
        } else {
            cout << " Czas wyjazdu: 0" << mK[i].getCzasWyjazduGodz();
        }

        if(mK[i].getCzasWyjazduMin() > 9 && mK[i].getCzasWyjazduMin() < 59) {
            cout << ":" << mK[i].getCzasWyjazduMin() << "." << endl;
        } else {
            cout << ":0" << mK[i].getCzasWyjazduMin() << "." << endl;
        }
    }

    if(getch()) {
        system("cls");
        pokazElementyKursow(mK);
    }
}

void dodajKurs(vector<Kurs> &mK) {
    int godzina = 0;
    int minuty = 0;
    int ilosc = 0;

    cout << "Podaj godzine o ktorej zacznie sie kurs: \n";
    cin >> godzina;

    cout << "Podaj liczbe minut o ktorej zacznie sie kurs: \n";
    cin >> minuty;

    mK.push_back(Kurs());
    ilosc = mK.size();
    mK[ilosc - 1].setKurs(godzina, minuty);

    system("cls");
    pokazElementyKursow(mK);
}

void usunKurs(vector<Kurs> &mK) {
    unsigned int id = 0;

    cout << "Podaj ID kursu, ktory chcesz usunac: \n";
    cin >> id;

    if(id > mK.size()) {
        cout << "Taki kurs nie istnieje!" << endl;
    } else {
        mK.erase(mK.begin() + id);
    }

    system("cls");
    pokazElementyKursow(mK);
}