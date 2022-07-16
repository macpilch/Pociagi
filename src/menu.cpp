/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: menu.cpp
    Data: 14.07.2022
    Modyfikacja: 16.07.2022
*/

#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

extern vecM myMiejsca;
extern vecP myPociagi;
extern vecK myKursy;

int nrMiejsca[MAX_BILETOW];
int nrPociagu[MAX_BILETOW];
int nrKursu[MAX_BILETOW];

bilet b, *bWsk = &b;

void pokazMenu(void) {
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***\n";
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. ZAKUP BILETU.\n2. MIEJSCA.\n3. POCIAGI.\n4. KURSY.\n5. PODSUMOWANIE.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        if(bWsk->ilosc != (MAX_BILETOW + 1)) {
            system("cls");
            wybierzBilet();
        } else {
            system("cls");
            cout << "Posiadasz juz maksymalna liczbe biletow!\n\n";
            pokazMenu();
        }
        break;
    case 2:
        system("cls");
        pokazElementyMiejsc(myMiejsca);
        break;
    case 3:
        system("cls");
        pokazElementyPociagow(myPociagi);
        break;
    case 4:
        system("cls");
        pokazElementyKursow(myKursy);
        break;
    case 5:
        system("cls");
        pokazPodsumowanie();
        break;
    default:
        system("cls");
        pokazMenu();
        break;
    }

    for(int i = 0; MAX_BILETOW; i++) {
        nrMiejsca[i] = -1;
        nrPociagu[i] = -1;
        nrKursu[i] = -1;
    }
}

void obliczanieCzasu(void) {
    double predPociagu = 0;
    double odleglosc = 0;
    int godz = 0;
    int min = 0;
    int t = 0;

    predPociagu = myPociagi[nrPociagu[bWsk->nr - 1] - 1].getPredkosc();
    odleglosc = myMiejsca[nrMiejsca[bWsk->nr - 1] - 1].getOdleglosc();

    myKursy[nrKursu[bWsk->nr - 1] - 1].czasPodrozy = (odleglosc / predPociagu) * GODZ_W_SEK;
    t = myKursy[nrKursu[bWsk->nr - 1] - 1].czasPodrozy;

    godz = t / GODZ_W_SEK;
    t %= GODZ_W_SEK;
    min = t / GODZ_W_MIN;
    t %= GODZ_W_MIN;

    cout << "Kurs wyniesie: " << godz << " Godz. i " << min << " Min.\n";

    if((min + myKursy[nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.min) > GODZ_W_MIN) {
        godz++;
        myKursy[nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.godz = myKursy[nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.min = (myKursy[nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.min + min) - GODZ_W_MIN;
    } else {
        myKursy[nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.godz = myKursy[nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu[bWsk->nr - 1] - 1].czasPrzyjazdu.min = myKursy[nrKursu[bWsk->nr - 1] - 1].czasWyjazdu.min + min;
    }
}

void wybierzBilet(void) {
    static int posiadanaGotowka = 100;
    int rodzajBiletu = 1;
    
    if((bWsk->ilosc + 1) == (MAX_BILETOW + 1)) {
        system("cls");
        cout << "Nie mozna kupic wiecej niz 4 bilety!\n\n";

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
    cout << "Dostepne miejsca: \n";
    
    for(uInt i = 0; i < myMiejsca.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << myMiejsca[i].getNazwa();
        cout << " Odleglosc: " << myMiejsca[i].getOdleglosc() << " km.\n";
    }

    cout << "\nPodaj numer miejsca, ktory chcesz wybrac: ";
    cin >> nrMiejsca[bWsk->nr - 1];

    if((uInt)nrMiejsca[bWsk->nr - 1] > myMiejsca.size() || (uInt)nrMiejsca[bWsk->nr - 1] <= 0) {
        system("cls");
        wybierzMiejsce();
    } else {
        system("cls");
        wybierzPociag();
    }
}

void wybierzPociag(void) {
    cout << "Dostepne pociagi: \n";
    
    for(uInt i = 0; i < myPociagi.size(); i++) {
        cout << "Nr. " << i + 1 << " Nazwa: " << myPociagi[i].getNazwa();
        cout << " Predkosc: " << myPociagi[i].getPredkosc() << " km/h.\n";
    }

    cout << "\nPodaj numer pociagu, ktory chcesz wybrac: ";
    cin >> nrPociagu[bWsk->nr - 1];

    if((uInt)nrPociagu[bWsk->nr - 1] > myPociagi.size() || (uInt)nrPociagu[bWsk->nr - 1] <= 0) {
        system("cls");
        wybierzPociag();
    } else {
        system("cls");
        wybierzKurs();
    }
}

void wybierzKurs(void) {
    cout << "Dostepne kursy: \n";

    for(uInt i = 0; i < myKursy.size(); i++) {
        cout << "Nr. " << i + 1;

        if(myKursy[i].czasWyjazdu.godz > 9 && myKursy[i].czasWyjazdu.godz < 24) {
            cout << " Czas wyjazdu: " << myKursy[i].czasWyjazdu.godz;
        } else {
            cout << " Czas wyjazdu: 0" << myKursy[i].czasWyjazdu.godz;
        }

        if(myKursy[i].czasWyjazdu.min > 9 && myKursy[i].czasWyjazdu.min < 59) {
            cout << ":" << myKursy[i].czasWyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[i].czasWyjazdu.min << ".\n";
        }
    }

    cout << "\nPodaj numer kursu, ktory chcesz wybrac: ";
    cin >> nrKursu[bWsk->nr - 1];

    if((uInt)nrKursu[bWsk->nr - 1] > myKursy.size() || (uInt)nrKursu[bWsk->nr - 1] <= 0) {
        system("cls");
        wybierzKurs();
    } else {
        system("cls");
        pokazPodsumowanie();
    }
}

void pokazPodsumowanie(void) {
    static int nrStrony = MAX_ROZ_STR;
    
    if(!bWsk->ilosc) {
        cout << "Brak biletu!\n\n";
        cout << "Miejscowosc: Brak.\n";
        cout << "Pociag: Brak.\n";
        cout << "Nr. biletu: Brak.\n";
        cout << "Nr. kursu: Brak.\n";
        cout << "Czas wyjazdu pociagu: Brak.\n";
        cout << "Czas przyjazdu pociagu: Brak.\n";
        cout << "\nNacisnij ESC aby powrocic do glownego menu.";

        if(getch() == K_ESC) {
            system("cls");
            pokazMenu();
        } else {
            system("cls");
            pokazPodsumowanie();
        }
    } else {
        cout << "*** Wszystkie dane biletu: ***\n";
        cout << "Miejscowosc: " << myMiejsca[nrMiejsca[bWsk->nr - nrStrony] - 1].getNazwa() << ".\n";
        cout << "Pociag: " << myPociagi[nrPociagu[bWsk->nr - nrStrony] - 1].getNazwa() << ".\n";
        cout << "Nr. biletu: " << (bWsk->nr - nrStrony) + 1 << ".\n";
        cout << "Nr. kursu: " << nrKursu[bWsk->nr - nrStrony] << ".\n";
        obliczanieCzasu();

        if(myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz > 9 && myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz < 24) {
            cout << "Czas wyjazdu pociagu: " << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz;
        } else {
            cout << "Czas wyjazdu pociagu: 0" << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.godz;
        }

        if(myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min > 9 && myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasWyjazdu.min << ".\n";
        }

        if(myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz > 9 && myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz < 24) {
            cout << "Czas przyjazdu pociagu: " << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz;
        } else {
            cout << "Czas przyjazdu pociagu: 0" << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.godz;
        }

        if(myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min > 9 && myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[nrKursu[bWsk->nr - nrStrony] - 1].czasPrzyjazdu.min << ".\n";
        }

        cout << "\nNacisnij ESC aby powrocic do glownego menu.";
        cout << "\nNacisnij <- lub -> aby przegladac zakupione bilety.\n";

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