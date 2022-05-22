#include <iostream>
#include "../inc/funkcje.h"

#define GODZ_W_SEK 3600
#define GODZ_W_MIN 60

using namespace std;

vector<Miejsce> myMiejsca;
vector<Pociag> myPociagi;
vector<Kurs> myKursy;

int nrMiejsca = -1;
int nrPociagu = -1;
int nrKursu = -1;

int posiadanaGotowka = 100;
int rodzajBiletu = 1;

int main(int argc, char *argv[]) {
    //cout << "Argv: " << argv[1] << endl;
    
    wczytajMiejsce(myMiejsca);
    wczytajPociagi(myPociagi);
    wczytajKursy(myKursy);
    pokazMenu();
    return 0;
}

void pokazMenu(void) {
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***\n";
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. ZAKUP BILETU.\n2. MIEJSCA.\n3. POCIAGI.\n4. KURSY.\n5. PODSUMOWANIE.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        system("cls");
        wybierzBilet();
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
}

void obliczanieCzasu(void) {
    double predPociagu = 0;
    double odleglosc = 0;
    int godz = 0;
    int min = 0;
    int t = 0;

    predPociagu = myPociagi[nrPociagu - 1].getPredkosc();
    odleglosc = myMiejsca[nrMiejsca - 1].getOdleglosc();

    myKursy[nrKursu - 1].czasPodrozy = (odleglosc / predPociagu) * GODZ_W_SEK;
    t = myKursy[nrKursu - 1].czasPodrozy;

    godz = t / GODZ_W_SEK;
    t %= GODZ_W_SEK;
    min = t / GODZ_W_MIN;
    t %= GODZ_W_MIN;

    cout << "Kurs wyniesie: " << godz << " Godz. i " << min << " Min.\n";

    if((min + myKursy[nrKursu - 1].czasWyjazdu.min) > GODZ_W_MIN) {
        godz++;
        myKursy[nrKursu - 1].czasPrzyjazdu.godz = myKursy[nrKursu - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu - 1].czasPrzyjazdu.min = (myKursy[nrKursu - 1].czasWyjazdu.min + min) - GODZ_W_MIN;
    } else {
        myKursy[nrKursu - 1].czasPrzyjazdu.godz = myKursy[nrKursu - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu - 1].czasPrzyjazdu.min = myKursy[nrKursu - 1].czasWyjazdu.min + min;
    }
}

void wybierzBilet(void) {
    cout << "Posiadana przez ciebie gotowka: " << posiadanaGotowka << endl;
    cout << "\nPodaj numer biletu ktory chcesz kupic (1. Normalny - 20 zl, 2. Ulgowy - 15 zl):\n";
    cin >> rodzajBiletu;

    switch(rodzajBiletu) {
    case 1:
        posiadanaGotowka -= 20;
        break;
    case 2:
        posiadanaGotowka -= 15;
        break;
    }

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
    cin >> nrMiejsca;

    if((uInt)nrMiejsca > myMiejsca.size()) {
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
    cin >> nrPociagu;

    if((uInt)nrPociagu > myPociagi.size()) {
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
    cin >> nrKursu;

    if((uInt)nrKursu > myKursy.size()) {
        system("cls");
        wybierzKurs();
    } else {
        system("cls");
        pokazPodsumowanie();
    }
}

void pokazPodsumowanie(void) {
    cout << "*** Wszystkie dane biletu: ***\n";

    if(nrMiejsca != -1) {
        cout << "Miejscowosc: " << myMiejsca[nrMiejsca - 1].getNazwa() << ".\n";
    } else {
        cout << "Miejscowosc: Brak.\n";
    }

    if(nrPociagu != -1) {
        cout << "Pociag: " << myPociagi[nrPociagu - 1].getNazwa() << ".\n";
    } else {
        cout << "Pociag: Brak.\n";
    }

    if(nrKursu != -1) {
        cout << "Nr. kursu: " << nrKursu << ".\n";
        obliczanieCzasu();

        if(myKursy[nrKursu - 1].czasWyjazdu.godz > 9 && myKursy[nrKursu - 1].czasWyjazdu.godz < 24) {
            cout << "Czas wyjazdu pociagu: " << myKursy[nrKursu - 1].czasWyjazdu.godz;
        } else {
            cout << "Czas wyjazdu pociagu: 0" << myKursy[nrKursu - 1].czasWyjazdu.godz;
        }

        if(myKursy[nrKursu - 1].czasWyjazdu.min > 9 && myKursy[nrKursu - 1].czasWyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu - 1].czasWyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[nrKursu - 1].czasWyjazdu.min << ".\n";
        }

        if(myKursy[nrKursu - 1].czasPrzyjazdu.godz > 9 && myKursy[nrKursu - 1].czasPrzyjazdu.godz < 24) {
            cout << "Czas przyjazdu pociagu: " << myKursy[nrKursu - 1].czasPrzyjazdu.godz;
        } else {
            cout << "Czas przyjazdu pociagu: 0" << myKursy[nrKursu - 1].czasPrzyjazdu.godz;
        }

        if(myKursy[nrKursu - 1].czasPrzyjazdu.min > 9 && myKursy[nrKursu - 1].czasPrzyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu - 1].czasPrzyjazdu.min << ".\n";
        } else {
            cout << ":0" << myKursy[nrKursu - 1].czasPrzyjazdu.min << ".\n";
        }
    } else {
        cout << "Nr. kursu: Brak.\n";
        cout << "Czas wyjazdu pociagu: Brak.\n";
        cout << "Czas przyjazdu pociagu: Brak.\n";
    }

    cout << "\nNacisnij dowolny przycisk aby powrocic do glownego menu.";

    if(getch()) {
        system("cls");
        pokazMenu();
    }
}