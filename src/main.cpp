#include <iostream>
#include <vector>
#include <windows.h>
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

int main() {
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

    cout << "1. Pokaz miejsca do wybrania.\n2. Dodaj nowe miejsce.\n3. Usun miejsce.\n";
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

void pokaz_miejsca(void) {
    for(int i = 0; i < myMiejsca.size(); i++) {
        cout << "Miejscowosc: " << myMiejsca[i].get_nazwa() << endl;
        cout << "Odleglosc: " << myMiejsca[i].get_odleglosc() << endl;
    }

    pokaz_elementy_miejsc();
}

void dodaj_miejsce(void) {
    string nazwa;
    int odlg;
    static int ilosc;
    
    cout << "Podaj nazwe miejscowosci ktora chcesz dodac: \n";
    cin >> nazwa;

    cout << "Podaj odleglosc od tej miejscowosci: \n";
    cin >> odlg;

    myMiejsca.push_back(Miejsce());
    myMiejsca[ilosc++].set_miejsce(nazwa, odlg);
    pokaz_elementy_miejsc();
}

void usun_miejsce(void) {
    int id = 0;

    cout << "Podaj ID miejsca, ktore chcesz usunac: \n";
    cin >> id;

    myMiejsca.erase(myMiejsca.begin() + id);
    pokaz_elementy_miejsc();
}

void pokaz_pociagi(void) {
    for(int i = 0; i < myPociagi.size(); i++) {
        cout << "Nazwa: " << myPociagi[i].get_nazwa() << endl;
        cout << "Predkosc: " << myPociagi[i].get_predkosc() << endl;
        cout << "Dostepnosc: " << myPociagi[i].get_dostepnosc() << endl;
    }

    pokaz_elementy_pociagow();
}

void dodaj_pociag(void) {
    string nazwa;
    int predkosc;
    static int ilosc;
    
    cout << "Podaj nazwe pociagu ktora chcesz dodac: \n";
    cin >> nazwa;

    cout << "Podaj predkosc pociagu: \n";
    cin >> predkosc;

    myPociagi.push_back(Pociag());
    myPociagi[ilosc++].set_pociag_nazwa(nazwa);
    myPociagi[ilosc++].set_pociag_pred(predkosc);
    myPociagi[ilosc++].set_pociag_dost(true);
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
    for(int i = 0; i < myTory.size(); i++) {
        cout << "Poczatek: " << myTory[i].get_poczatek() << endl;
        cout << "Koniec: " << myTory[i].get_koniec() << endl;
    }

    pokaz_elementy_torow();
}

void dodaj_tor(void) {
    int poczatek;
    static int ilosc;
    
    cout << "Podaj poczatek toru ktory chcesz dodac: \n";
    cin >> poczatek;

    myTory.push_back(Tor());
    myTory[ilosc++].set_poczatek(poczatek);
    myTory[ilosc++].set_dostepnosc(true);
    pokaz_elementy_torow();
}

void usun_tor(void) {
    int id = 0;

    cout << "Podaj ID toru, ktore chcesz usunac: \n";
    cin >> id;

    myTory.erase(myTory.begin() + id);
    pokaz_elementy_torow();
}