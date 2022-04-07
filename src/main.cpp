#include <iostream>
#include "../inc/funkcje.h"

using namespace std;

vector<Miejsce> myMiejsca;
vector<Pociag> myPociagi;
vector<Kurs> myKursy;

int nrMiejsca = -1;
int nrPociagu = -1;
int nrKursu = -1;

int main(void) {
    wczytajMiejsce(myMiejsca);
    wczytajPociagi(myPociagi);
    wczytajKursy(myKursy);
    pokazMenu();
    return 0;
}

void pokazMenu(void) {
    int wybor = 0;

    cout << "*** Witamy na Dworcu Centralnym w Rzeszowie! ***" << endl;
    cout << "MENU (wybierz odpowiednia opcje): \n\n1. ZAKUP BILETU\n2. MIEJSCA.\n3. POCIAGI.\n4. KURSY.\n5. PODSUMOWANIE.\n";
    cin >> wybor;

    switch(wybor) {
    case 1:
        system("cls");
        wybierzMiejsce();
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

    myKursy[nrKursu - 1].czasPodrozy = (odleglosc / predPociagu) * 3600;
    t = myKursy[nrKursu - 1].czasPodrozy;

    godz = t / 3600;
    t %= 3600;
    min = t / 60;
    t %= 60;

    cout << "Kurs wyniesie: " << godz << " Godz. i " << min << " Min." << endl;

    if((min + myKursy[nrKursu - 1].czasWyjazdu.min) > 60) {
        godz++;
        myKursy[nrKursu - 1].czasPrzyjazdu.godz = myKursy[nrKursu - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu - 1].czasPrzyjazdu.min = (myKursy[nrKursu - 1].czasWyjazdu.min + min) - 60;
    } else {
        myKursy[nrKursu - 1].czasPrzyjazdu.godz = myKursy[nrKursu - 1].czasWyjazdu.godz + godz;
        myKursy[nrKursu - 1].czasPrzyjazdu.min = myKursy[nrKursu - 1].czasWyjazdu.min + min;
    }
}

void wybierzMiejsce(void) {
    cout << "Dostepne miejsca: " << endl;
    
    for(unsigned int i = 0; i < myMiejsca.size(); i++) {
        cout << "Nr. " << i + 1 << " Miejscowosc: " << myMiejsca[i].getNazwa();
        cout << " Odleglosc: " << myMiejsca[i].getOdleglosc() << " km." << endl;
    }

    cout << "\nPodaj numer miejsca, ktory chcesz wybrac: ";
    cin >> nrMiejsca;

    if((unsigned int)nrMiejsca > myMiejsca.size()) {
        system("cls");
        wybierzMiejsce();
    } else {
        system("cls");
        wybierzPociag();
    }
}

void wybierzPociag(void) {
    cout << "Dostepne pociagi: " << endl;
    
    for(unsigned int i = 0; i < myPociagi.size(); i++) {
        cout << "Nr. " << i + 1 << " Nazwa: " << myPociagi[i].getNazwa();
        cout << " Predkosc: " << myPociagi[i].getPredkosc() << " km/h." << endl;
    }

    cout << "\nPodaj numer pociagu, ktory chcesz wybrac: ";
    cin >> nrPociagu;

    if((unsigned int)nrPociagu > myPociagi.size()) {
        system("cls");
        wybierzPociag();
    } else {
        system("cls");
        wybierzKurs();
    }
}

void wybierzKurs(void) {
    cout << "Dostepne kursy: " << endl;

    for(unsigned int i = 0; i < myKursy.size(); i++) {
        cout << "Nr. " << i + 1;

        if(myKursy[i].getCzasWyjazduGodz() > 9 && myKursy[i].getCzasWyjazduGodz() < 24) {
            cout << " Czas wyjazdu: " << myKursy[i].getCzasWyjazduGodz();
        } else {
            cout << " Czas wyjazdu: 0" << myKursy[i].getCzasWyjazduGodz();
        }

        if(myKursy[i].getCzasWyjazduMin() > 9 && myKursy[i].getCzasWyjazduMin() < 59) {
            cout << ":" << myKursy[i].getCzasWyjazduMin() << "." << endl;
        } else {
            cout << ":0" << myKursy[i].getCzasWyjazduMin() << "." << endl;
        }
    }

    cout << "\nPodaj numer kursu, ktory chcesz wybrac: ";
    cin >> nrKursu;

    if((unsigned int)nrKursu > myKursy.size()) {
        system("cls");
        wybierzKurs();
    } else {
        system("cls");
        pokazPodsumowanie();
    }
}

void pokazPodsumowanie(void) {
    cout << "*** Wszystkie dane biletu: ***" << endl;

    if(nrMiejsca != -1) {
        cout << "Miejscowosc: " << myMiejsca[nrMiejsca - 1].getNazwa() << endl;
    } else {
        cout << "Miejscowosc: Brak." << endl;
    }

    if(nrPociagu != -1) {
        cout << "Pociag: " << myPociagi[nrPociagu - 1].getNazwa() << endl;
    } else {
        cout << "Pociag: Brak." << endl;
    }

    if(nrKursu != -1) {
        cout << "Nr. kursu: " << nrKursu << endl;
        obliczanieCzasu();

        if(myKursy[nrKursu - 1].getCzasWyjazduGodz() > 9 && myKursy[nrKursu - 1].getCzasWyjazduGodz() < 24) {
            cout << "Czas wyjazdu pociagu: " << myKursy[nrKursu - 1].getCzasWyjazduGodz();
        } else {
            cout << "Czas wyjazdu pociagu: 0" << myKursy[nrKursu - 1].getCzasWyjazduGodz();
        }

        if(myKursy[nrKursu - 1].getCzasWyjazduMin() > 9 && myKursy[nrKursu - 1].getCzasWyjazduMin() < 60) {
            cout << ":" << myKursy[nrKursu - 1].getCzasWyjazduMin() << endl;
        } else {
            cout << ":0" << myKursy[nrKursu - 1].getCzasWyjazduMin() << endl;
        }

        if(myKursy[nrKursu - 1].czasPrzyjazdu.godz > 9 && myKursy[nrKursu - 1].czasPrzyjazdu.godz < 24) {
            cout << "Czas przyjazdu pociagu: " << myKursy[nrKursu - 1].czasPrzyjazdu.godz;
        } else {
            cout << "Czas przyjazdu pociagu: 0" << myKursy[nrKursu - 1].czasPrzyjazdu.godz;
        }

        if(myKursy[nrKursu - 1].czasPrzyjazdu.min > 9 && myKursy[nrKursu - 1].czasPrzyjazdu.min < 60) {
            cout << ":" << myKursy[nrKursu - 1].czasPrzyjazdu.min << endl;
        } else {
            cout << ":0" << myKursy[nrKursu - 1].czasPrzyjazdu.min << endl;
        }
    } else {
        cout << "Nr. kursu: Brak." << endl;
        cout << "Czas wyjazdu pociagu: Brak." << endl;
        cout << "Czas przyjazdu pociagu: Brak." << endl;
    }

    cout << "\nNacisnij dowolny przycisk aby powrocic do glownego menu.";

    if(getch()) {
        system("cls");
        pokazMenu();
    }
}