#include <string.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "../inc/miejsca.h"
#include "../inc/pociagi.h"
#include "../inc/tory.h"

using namespace std;

vector <Miejsce> myMiejsca;
vector <Pociag> myPociagi;
vector <Tor> myTory;

void pokaz_menu(void);
void pokaz_elementy_miejsc(void);
void pokaz_elementy_pociagow(void);
void pokaz_elementy_torow(void);
void pokaz_miejsca(void);
void dodaj_miejsce(void);
void usun_miejsce(void);
void pokaz_pociagi(void);
void dodaj_pociag(void);
void usun_pociag(void);
void pokaz_tory(void);
void dodaj_tor(void);
void usun_tor(void);
void zapisz_miejsce(void);
void wczytaj_miejsce(void);

int main(void) {
    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl << endl;
    pokaz_menu();
    return 0;
}

void pokaz_menu(void) {
    int wybor = 0;
    
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. MIEJSCA.\n2. POCIAGI.\n3. TORY.\n";
    cin >> wybor;

    switch(wybor) {
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

void pokaz_elementy_miejsc(void) {
    int wybor = 0;

    cout << "1. Pokaz miejsca do wybrania.\n2. Dodaj nowe miejsce.\n3. Usun miejsce.\n4. Zapis miejsc do pliku.\n5. Wczytaj miejsca z pliku.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        pokaz_miejsca();
        break;
    case 2:
        dodaj_miejsce();
        break;
    case 3:
        usun_miejsce();
        break;
    case 4:
        zapisz_miejsce();
        break;
    case 5:
        wczytaj_miejsce();
        break;
    }
}

void pokaz_elementy_pociagow(void) {
    int wybor = 0;
    
    cout << "1. Pokaz pociagi do wybrania.\n2. Dodaj nowy pociag.\n3. Usun pociag.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        pokaz_pociagi();
        break;
    case 2:
        dodaj_pociag();
        break;
    case 3:
        usun_pociag();
        break;
    }
}

void pokaz_elementy_torow(void) {
    int wybor = 0;

    cout << "1. Pokaz tory do wybrania.\n2. Dodaj nowy tor.\n3. Usun tor.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        pokaz_tory();
        break;
    case 2:
        dodaj_tor();
        break;
    case 3:
        usun_tor();
        break;
    }    
}

void zapisz_miejsce(void) {
    fstream plik_baza_miejsc;
    int wielkosc = myMiejsca.size();

    plik_baza_miejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in);

    if(plik_baza_miejsc.is_open()) {
        cout << "Plik otwarto!";

        plik_baza_miejsc << wielkosc << endl;

        for(int i = 0; i < wielkosc; i++) {
            plik_baza_miejsc << myMiejsca[i].get_nazwa() << endl;
            plik_baza_miejsc << myMiejsca[i].get_odleglosc() << endl;
            plik_baza_miejsc << myMiejsca[i].get_stworzone() << endl;
        }
    } else {
        cout << "Brak pliku z baza danych miejsc!";
    }

    plik_baza_miejsc.close();
    pokaz_elementy_miejsc();
}

void wczytaj_miejsce(void) {
    fstream plik_baza_miejsc;
    string tmpNazwa;
    int tmpOdlg;
    bool tmpStw;
    int wielkosc = 0;

    plik_baza_miejsc.open("C:/Users/Maciek/Documents/Szkola/2TRA/PP/Pociagi/miejsca", fstream::out | fstream::in);

    if(plik_baza_miejsc.is_open()) {
        cout << "Plik otwarto!";

        plik_baza_miejsc >> wielkosc;
        myMiejsca.clear();

        for(int i = 0; i < wielkosc; i++) {
            plik_baza_miejsc >> tmpNazwa;
            plik_baza_miejsc >> tmpOdlg;
            plik_baza_miejsc >> tmpStw;

            myMiejsca.push_back(Miejsce());
            myMiejsca[i].set_miejsce(tmpNazwa, tmpOdlg, tmpStw);
        }
    } else {
        cout << "Brak pliku z baza danych miejsc!";
    }

    plik_baza_miejsc.close();
    pokaz_elementy_miejsc();
}

void pokaz_miejsca(void) {
    for(unsigned int i = 0; i < myMiejsca.size(); i++) {
        cout << "Miejscowosc: " << myMiejsca[i].get_nazwa() << endl;
        cout << "Odleglosc: " << myMiejsca[i].get_odleglosc() << endl;
    }

    pokaz_elementy_miejsc();
}

void dodaj_miejsce(void) {
    string nazwa;
    int odlg = 0;
    int ilosc = 0;
    
    cout << "Podaj nazwe miejscowosci ktora chcesz dodac: \n";
    cin >> nazwa;

    for(unsigned int i = 0; i < myMiejsca.size(); i++) {
        if(nazwa == myMiejsca[i].get_nazwa()) {
            cout << "Taka nazwa juz istnieje!";
            break;
        }
    }

    cout << "Podaj odleglosc od tej miejscowosci: \n";
    cin >> odlg;

    myMiejsca.push_back(Miejsce());
    ilosc = myMiejsca.size();
    myMiejsca[ilosc - 1].set_miejsce(nazwa, odlg, true);
    
    pokaz_elementy_miejsc();
}

void usun_miejsce(void) {
    int id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: \n";
    cin >> id;

    if(!myMiejsca[id].get_stworzone()) {
        cout << "Takie miejsce nie istnieje!" << endl;
    } else {
        myMiejsca.erase(myMiejsca.begin() + id);
    }
    
    pokaz_elementy_miejsc();
}

void pokaz_pociagi(void) {
    for(unsigned int i = 0; i < myPociagi.size(); i++) {
        cout << "Nazwa: " << myPociagi[i].get_nazwa() << endl;
        cout << "Predkosc: " << myPociagi[i].get_predkosc() << endl;
        cout << "Dostepnosc: " << myPociagi[i].get_dostepnosc() << endl;
    }

    pokaz_elementy_pociagow();
}

void dodaj_pociag(void) {
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
    myPociagi[ilosc - 1].set_pociag_dost(true);
    pokaz_elementy_pociagow();
}

void usun_pociag(void) {
    int id = 0;

    cout << "Podaj ID pociagu, ktore chcesz usunac: \n";
    cin >> id;

    myPociagi.erase(myPociagi.begin() + id);
    pokaz_elementy_pociagow();
}

void pokaz_tory(void) {
    for(unsigned int i = 0; i < myTory.size(); i++) {
        cout << "Poczatek: " << myTory[i].get_poczatek() << endl;
        cout << "Koniec: " << myTory[i].get_koniec() << endl;
    }

    pokaz_elementy_torow();
}

void dodaj_tor(void) {
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

void usun_tor(void) {
    int id = 0;

    cout << "Podaj ID toru, ktore chcesz usunac: \n";
    cin >> id;

    myTory.erase(myTory.begin() + id);
    pokaz_elementy_torow();
}