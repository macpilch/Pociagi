#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

extern vector<Miejsce> myMiejsca;
extern vector<Pociag> myPociagi;
extern vector<Kurs> myKursy;

int nrMiejsca[4];
int nrPociagu[4];
int nrKursu[4];

int posiadanaGotowka = 100;
int rodzajBiletu = 1;
int iloscBiletow;

void pokazMenu(void) {
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***\n";
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. ZAKUP BILETU.\n2. MIEJSCA.\n3. POCIAGI.\n4. KURSY.\n5. PODSUMOWANIE.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        if(iloscBiletow != -1) {
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

    predPociagu = myPociagi[nrPociagu[iloscBiletow - 1] - 1].getPredkosc();
    odleglosc = myMiejsca[nrMiejsca[iloscBiletow - 1] - 1].getOdleglosc();

    myKursy[nrKursu[iloscBiletow - 1] - 1].czasPodrozy = (odleglosc / predPociagu) * GODZ_W_SEK;
    t = myKursy[nrKursu[iloscBiletow - 1] - 1].czasPodrozy;

    godz = t / GODZ_W_SEK;
    t %= GODZ_W_SEK;
    min = t / GODZ_W_MIN;
    t %= GODZ_W_MIN;

    cout << "Kurs wyniesie: " << godz << " Godz. i " << min << " Min.\n";

    if((min + myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min) > GODZ_W_MIN) {
        godz++;
        myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.godz = myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.min = (myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min + min) - GODZ_W_MIN;
    } else {
        myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.godz = myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.min = myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min + min;
    }
}

void wybierzBilet(void) {
    cout << "Posiadana przez ciebie gotowka: " << posiadanaGotowka << endl;
    cout << "To twoj " << iloscBiletow + 1 << " bilet." << endl;
    cout << "Podaj numer biletu ktory chcesz kupic (1. Normalny - 20 zl, 2. Ulgowy - 15 zl):" << endl;
    cin >> rodzajBiletu;

    switch(rodzajBiletu) {
    case 1:
        posiadanaGotowka -= 20;
        break;
    case 2:
        posiadanaGotowka -= 15;
        break;
    }

    iloscBiletow++;

    if(iloscBiletow == (MAX_BILETOW + 1)) {
        system("cls");
        cout << "Nie mozna kupic wiecej niz 4 bilety!\n\n";
        iloscBiletow = -1;
        pokazMenu();
    } else {
        system("cls");
        wybierzMiejsce();
    }
}

void wybierzMiejsce(void) {
    cout << "Dostepne miejsca: \n";
    
    for(uInt i = 0; i < myMiejsca.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << myMiejsca[i].getNazwa();
        cout << " Odleglosc: " << myMiejsca[i].getOdleglosc() << " km.\n";
    }

    cout << "\nPodaj numer miejsca, ktory chcesz wybrac: ";
    cin >> nrMiejsca[iloscBiletow - 1];

    if((uInt)nrMiejsca[iloscBiletow - 1] > myMiejsca.size()) {
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
    cin >> nrPociagu[iloscBiletow - 1];

    if((uInt)nrPociagu[iloscBiletow - 1] > myPociagi.size()) {
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
    cin >> nrKursu[iloscBiletow - 1];

    if((uInt)nrKursu[iloscBiletow - 1] > myKursy.size()) {
        system("cls");
        wybierzKurs();
    } else {
        system("cls");
        pokazPodsumowanie();
    }
}

void pokazPodsumowanie(void) {
    if(!iloscBiletow) {
        cout << "Brak biletu!\n\n";
        cout << "Miejscowosc: Brak.\n";
        cout << "Pociag: Brak.\n";
        cout << "Nr. kursu: Brak.\n";
        cout << "Czas wyjazdu pociagu: Brak.\n";
        cout << "Czas przyjazdu pociagu: Brak.\n";
    } else {
        cout << "*** Wszystkie dane " << iloscBiletow << " biletu: ***\n";
        cout << "Miejscowosc: " << myMiejsca[nrMiejsca[iloscBiletow - 1] - 1].getNazwa() << ".\n";
        cout << "Pociag: " << myPociagi[nrPociagu[iloscBiletow - 1] - 1].getNazwa() << ".\n";
        cout << "Nr. kursu: " << nrKursu[iloscBiletow - 1] << ".\n";
        obliczanieCzasu();

        if(myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.godz > 9 && myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.godz < 24) {
            cout << "Czas wyjazdu pociagu: " << myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.godz;
        } else {
            cout << "Czas wyjazdu pociagu: 0" << myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.godz;
        }

        if(myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min > 9 && myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[nrKursu[iloscBiletow - 1] - 1].czasWyjazdu.min << ".\n";
        }

        if(myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.godz > 9 && myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.godz < 24) {
            cout << "Czas przyjazdu pociagu: " << myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.godz;
        } else {
            cout << "Czas przyjazdu pociagu: 0" << myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.godz;
        }

        if(myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.min > 9 && myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[nrKursu[iloscBiletow - 1] - 1].czasPrzyjazdu.min << ".\n";
        }
    }

    cout << "\nNacisnij dowolny przycisk aby powrocic do glownego menu.";

    if(getch()) {
        system("cls");
        pokazMenu();
    }
}