/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: menu.cpp
    Data: 14.07.2022
    Modyfikacja: 31.08.2022
*/

#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

extern VECM myMiejsca;
extern VECP myPociagi;
extern VECK myKursy;

Bilet b;
Bilet *bWsk = &b;

void pokazMenu(void) {
    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl;
    cout << "MENU (wybierz odpowiednia opcje): " << endl << endl << "1. ZAKUP BILETU." << endl << "2. MIEJSCA." << endl << "3. POCIAGI." << endl << "4. KURSY." << endl << "5. PODSUMOWANIE." << endl;

    switch(getch()) {
    case K_KLAW_1:
        if(bWsk->ilosc != (MAX_BILETOW + 1)) {
            system("cls");
            wybierzBilet();
        } else {
            system("cls");
            cout << "Posiadasz juz maksymalna liczbe biletow!" << endl << endl;
            pokazMenu();
        }
        break;
    case K_KLAW_2:
        system("cls");
        pokazElementyMiejsc(myMiejsca);
        break;
    case K_KLAW_3:
        system("cls");
        pokazElementyPociagow(myPociagi);
        break;
    case K_KLAW_4:
        system("cls");
        pokazElementyKursow(myKursy);
        break;
    case K_KLAW_5:
        system("cls");
        pokazPodsumowanie();
        break;
    default:
        system("cls");
        pokazMenu();
        break;
    }

    for(int i = 0; i < MAX_BILETOW; i++) {
        bWsk->nrMiejsca[i] = -1;
        bWsk->nrPociagu[i] = -1;
        bWsk->nrKursu[i] = -1;
    }
}

void obliczanieCzasu(int &godz, int &min) {
    double predPociagu = 0;
    double odleglosc = 0;
    int t = 0;

    predPociagu = myPociagi[bWsk->nrPociagu[bWsk->nr - 1] - 1].getPredkosc();
    odleglosc = myMiejsca[bWsk->nrMiejsca[bWsk->nr - 1] - 1].getOdleglosc();

    myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasPodrozy = (odleglosc / predPociagu) * GODZ_W_SEK;
    t = myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasPodrozy;

    godz = t / GODZ_W_SEK;
    t %= GODZ_W_SEK;
    min = t / GODZ_W_MIN;
    t %= GODZ_W_MIN;

    if((min + myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.min) > GODZ_W_MIN) {
        godz++;
        myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.godz = myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.godz + godz;
        myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.min = (myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.min + min) - GODZ_W_MIN;
    } else {
        myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.godz = myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.godz + godz;
        myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.min = myKursy[bWsk->nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.min + min;
    }
}

void wybierzBilet(void) {
    static int posiadanaGotowka = 100;
    int rodzajBiletu = 1;
    
    if((bWsk->ilosc + 1) == (MAX_BILETOW + 1)) {
        system("cls");
        cout << "Nie mozna kupic wiecej niz 4 bilety!" << endl << endl;

        bWsk->ilosc = MAX_BILETOW + 1;

        pokazMenu();
        return;
    }

    cout << "Posiadana przez ciebie gotowka: " << posiadanaGotowka << endl;
    cout << "To twoj " << bWsk->ilosc + 1 << " bilet." << endl;
    cout << "Podaj numer biletu ktory chcesz kupic (1. Normalny - 20 zl, 2. Ulgowy - 15 zl):" << endl;
    cin >> rodzajBiletu;

    switch(rodzajBiletu) {
    case 1:
        posiadanaGotowka -= 20;
        break;
    case 2:
        posiadanaGotowka -= 15;
        break;
    default:
        system("cls");
        wybierzBilet();

        bWsk->ilosc = 0;
        bWsk->nr = 0;
        break;
    }

    bWsk->ilosc++;
    bWsk->nr = bWsk->ilosc;

    system("cls");
    wybierzMiejsce();
}

void wybierzMiejsce(void) {
    cout << "Dostepne miejsca: " << endl;
    
    for(UINT i = 0; i < myMiejsca.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << myMiejsca[i].getNazwa();
        cout << " Odleglosc: " << myMiejsca[i].getOdleglosc() << " km." << endl;
    }

    cout << endl << "Podaj numer miejsca, ktory chcesz wybrac: ";
    cin >> bWsk->nrMiejsca[bWsk->nr - 1];

    if((UINT)bWsk->nrMiejsca[bWsk->nr - 1] > myMiejsca.size() || (UINT)bWsk->nrMiejsca[bWsk->nr - 1] <= 0) {
        system("cls");
        wybierzMiejsce();
    } else {
        system("cls");
        wybierzPociag();
    }
}

void wybierzPociag(void) {
    cout << "Dostepne pociagi: " << endl;
    
    for(UINT i = 0; i < myPociagi.size(); i++) {
        cout << "Nr. " << i + 1 << " Nazwa: " << myPociagi[i].getNazwa();
        cout << " Predkosc: " << myPociagi[i].getPredkosc() << " km/h." << endl;
    }

    cout << endl << "Podaj numer pociagu, ktory chcesz wybrac: ";
    cin >> bWsk->nrPociagu[bWsk->nr - 1];

    if((UINT)bWsk->nrPociagu[bWsk->nr - 1] > myPociagi.size() || (UINT)bWsk->nrPociagu[bWsk->nr - 1] <= 0) {
        system("cls");
        wybierzPociag();
    } else if(!myPociagi[bWsk->nrPociagu[bWsk->nr - 1]].getDostepnosc()) {
        system("cls");
        cout << "Wybrany pociag jest juz w trasie!" << endl << endl;
        wybierzPociag();
    } else {
        myPociagi[bWsk->nrPociagu[bWsk->nr - 1]].setDostepnosc(false);

        system("cls");
        wybierzKurs();
    }
}

void wybierzKurs(void) {
    cout << "Dostepne kursy: " << endl;

    for(UINT i = 0; i < myKursy.size(); i++) {
        cout << "Nr. " << i + 1;

        if(myKursy[i].czasWyjazdu.godz > 9 && myKursy[i].czasWyjazdu.godz < 24) {
            cout << " Czas wyjazdu: " << myKursy[i].czasWyjazdu.godz;
        } else {
            cout << " Czas wyjazdu: 0" << myKursy[i].czasWyjazdu.godz;
        }

        if(myKursy[i].czasWyjazdu.min > 9 && myKursy[i].czasWyjazdu.min < 59) {
            cout << ":" << myKursy[i].czasWyjazdu.min << "." << endl;
        } else {
            cout << ":0" << myKursy[i].czasWyjazdu.min << "." << endl;
        }
    }

    cout << endl << "Podaj numer kursu, ktory chcesz wybrac: ";
    cin >> bWsk->nrKursu[bWsk->nr - 1];

    if((UINT)bWsk->nrKursu[bWsk->nr - 1] > myKursy.size() || (UINT)bWsk->nrKursu[bWsk->nr - 1] <= 0) {
        system("cls");
        wybierzKurs();
    } else if(!myKursy[bWsk->nrKursu[bWsk->nr - 1]].dostepnosc) {
        system("cls");
        cout << "Wybrany kurs o tej godz wlasnie trwa!" << endl << endl;
        wybierzKurs();
    } else {
        myKursy[bWsk->nrKursu[bWsk->nr - 1]].dostepnosc = false;

        system("cls");
        pokazPodsumowanie();
    }
}

void pokazPodsumowanie(void) {
    static int nrStrony = MAX_ROZ_STR;
    
    if(!bWsk->ilosc) {
        cout << "Brak biletu!" << endl << endl;
        cout << "Miejscowosc: Brak." << endl;
        cout << "Pociag: Brak." << endl;
        cout << "Nr. biletu: Brak." << endl;
        cout << "Nr. kursu: Brak." << endl;
        cout << "Kurs wyniesie: Brak." << endl;
        cout << "Czas wyjazdu pociagu: Brak." << endl;
        cout << "Czas przyjazdu pociagu: Brak." << endl;
        cout << endl << "Nacisnij ESC aby powrocic do glownego menu.";

        if(getch() == K_ESC) {
            system("cls");
            pokazMenu();
        } else {
            system("cls");
            pokazPodsumowanie();
        }
    } else {
        cout << "*** Wszystkie dane biletu: ***" << endl;
        cout << "Miejscowosc: " << myMiejsca[bWsk->nrMiejsca[bWsk->nr - nrStrony] - 1].getNazwa() << "." << endl;
        cout << "Pociag: " << myPociagi[bWsk->nrPociagu[bWsk->nr - nrStrony] - 1].getNazwa() << "." << endl;
        cout << "Nr. biletu: " << (bWsk->nr - nrStrony) + 1 << "." << endl;
        cout << "Nr. kursu: " << bWsk->nrKursu[bWsk->nr - nrStrony] << "." << endl;
        
        obliczanieCzasu(bWsk->godz[bWsk->nr - 1], bWsk->min[bWsk->nr - 1]);
        cout << "Kurs wyniesie: " << bWsk->godz[bWsk->nr - nrStrony] << " Godz. i " << bWsk->min[bWsk->nr - nrStrony] << " Min." << endl;

        if(myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz > 9 && myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz < 24) {
            cout << "Czas wyjazdu pociagu: " << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz;
        } else {
            cout << "Czas wyjazdu pociagu: 0" << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz;
        }

        if(myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min > 9 && myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min < 60) {
            cout << ":" << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min << "." << endl;
        } else {
            cout << ":0" << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min << "." << endl;
        }

        if(myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz > 9 && myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz < 24) {
            cout << "Czas przyjazdu pociagu: " << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz;
        } else {
            cout << "Czas przyjazdu pociagu: 0" << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz;
        }

        if(myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min > 9 && myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min < 60) {
            cout << ":" << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min << "." << endl;
        } else {
            cout << ":0" << myKursy[bWsk->nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min << "." << endl;
        }

        cout << endl << "Nacisnij ESC aby powrocic do glownego menu.";
        cout << endl << "Nacisnij <- lub -> aby przegladac zakupione bilety." << endl << endl;
        cout << "Strona: " << (bWsk->nr - nrStrony) + 1 << "/" << bWsk->nr << ".";

        switch(getch()) {
        case K_STRZ_L:
            nrStrony++;

            if(nrStrony == (bWsk->nr + MAX_ROZ_STR)) {
                nrStrony--;
            }

            system("cls");
            pokazPodsumowanie();
            break;
        case K_STRZ_P:
            nrStrony--;

            if(nrStrony == MIN_ROZ_STR) {
                nrStrony = MAX_ROZ_STR;
            }

            system("cls");
            pokazPodsumowanie();
            break;
        case K_ESC:
            system("cls");
            pokazMenu();
            break;
        default:
            system("cls");
            pokazPodsumowanie();
            break;
        }
    }
}