/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: kursy_funkcje.cpp
    Data: 09.03.2022
    Modyfikacja: 21.07.2022
*/

#include <iostream>
#include "../inc/kursy.h"
#include "../inc/funkcje.h"

using namespace std;

void pokazElementyKursow(vecK &mK) {
    cout << "MENU KURSOW (wybierz odpowiednia opcje): " << endl << endl << "1. Pokaz kursy do wybrania." << endl << "2. Dodaj nowy kurs." << endl << "3. Usun kurs." << endl << "4. Zapis kursow do pliku." << endl << "5. Powrot do menu." << endl;

    switch(getch()) {
    case K_KLAW_1:
        system("cls");
        pokazKursy(mK);
        break;
    case K_KLAW_2:
        system("cls");
        dodajKurs(mK);
        break;
    case K_KLAW_3:
        system("cls");
        usunKurs(mK);
        break;
    case K_KLAW_4:
        system("cls");
        zapiszKursy(mK);
        break;
    case K_KLAW_5:
        system("cls");
        pokazMenu();
        break;
    default:
        system("cls");
        pokazElementyKursow(mK);
        break;
    }
}

void zapiszKursy(vecK &mK) {
    fstream plikBazaKursow;
    int wielkosc = mK.size();

    plikBazaKursow.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/kursy", fstream::out | fstream::in | ios::trunc);

    if(plikBazaKursow.is_open()) {
        cout << "Plik otwarto!" << endl << "Dane zostaly pomyslnie zapisane." << endl << endl;

        plikBazaKursow << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plikBazaKursow << mK[i].czasWyjazdu.godz << endl;
            plikBazaKursow << mK[i].czasWyjazdu.min << endl;
        }
    } else {
        cout << "Brak pliku z baza danych kursow!" << endl << endl;
    }

    plikBazaKursow.close();
    pokazElementyKursow(mK);
}

void wczytajKursy(vecK &mK) {
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

void pokazKursy(vecK &mK) {
    cout << "Dostepne kursy: " << endl;
    
    for(uInt i = 0; i < mK.size(); i++) {
        cout << "Nr. " << i + 1;

        if(mK[i].czasWyjazdu.godz > 9 && mK[i].czasWyjazdu.godz < 24) {
            cout << " Czas wyjazdu: " << mK[i].czasWyjazdu.godz;
        } else {
            cout << " Czas wyjazdu: 0" << mK[i].czasWyjazdu.godz;
        }

        if(mK[i].czasWyjazdu.min > 9 && mK[i].czasWyjazdu.min < 59) {
            cout << ":" << mK[i].czasWyjazdu.min << "." << endl;
        } else {
            cout << ":0" << mK[i].czasWyjazdu.min << "." << endl;
        }
    }

    cout << endl << "Nacisnij ESC aby powrocic do menu.";

    if(getch() == K_ESC) {
        system("cls");
        pokazElementyKursow(mK);
    } else {
        system("cls");
        pokazKursy(mK);
    }
}

void dodajKurs(vecK &mK) {
    int godzina = 0;
    int minuty = 0;
    int ilosc = 0;

    if(mK.size() == MAX_KURSOW) {
        system("cls");
        cout << "Osiagnieto limit kursow (10)!" << endl << endl;
        pokazElementyKursow(mK);
    }

    cout << "Podaj godzine o ktorej zacznie sie kurs (Wolnych miejsc: " << (MAX_KURSOW - mK.size()) << "): " << endl;
    cin >> godzina;

    cout << "Podaj liczbe minut o ktorej zacznie sie kurs (Wolnych miejsc: " << (MAX_KURSOW - mK.size()) << "): " << endl;
    cin >> minuty;

    for(uInt i = 0; i < mK.size(); i++) {
        if(godzina == mK[i].czasWyjazdu.godz && minuty == mK[i].czasWyjazdu.min) {
            system("cls");
            cout << "Taki kurs juz istnieje!" << endl << endl;
            pokazElementyKursow(mK);
        }
    }

    mK.push_back(Kurs());
    ilosc = mK.size();
    mK[ilosc - 1].setKurs(godzina, minuty);
    mK[ilosc - 1].dostepnosc = true;

    system("cls");
    pokazElementyKursow(mK);
}

void usunKurs(vecK &mK) {
    uInt id = 0;

    cout << "Podaj ID kursu, ktory chcesz usunac: " << endl;
    cin >> id;

    if(id > mK.size()) {
        system("cls");
        cout << "Taki kurs nie istnieje!" << endl;
        pokazElementyKursow(mK);
    } else {
        mK.erase(mK.begin() + id);
        system("cls");
        pokazElementyKursow(mK);
    }
}