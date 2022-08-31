/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: funkcje.h
    Data: 09.03.2022
    Modyfikacja: 31.08.2022
*/

#ifndef __FUNKCJE_H__
#define __FUNKCJE_H__

#include <vector>
#include <windows.h>
#include <fstream>
#include <conio.h>

#include "../inc/makra.h"
#include "../inc/menu.h"
#include "../inc/miejsca.h"
#include "../inc/pociagi.h"
#include "../inc/kursy.h"

typedef vector<Miejsce> VECM;
typedef vector<Pociag> VECP;
typedef vector<Kurs> VECK;
typedef unsigned int UINT;

struct Bilet {
    int ilosc;
    int nr;
    int godz[MAX_BILETOW];
    int min[MAX_BILETOW];
    int nrMiejsca[MAX_BILETOW];
    int nrPociagu[MAX_BILETOW];
    int nrKursu[MAX_BILETOW];
};

void pokazElementyMiejsc(VECM &);
void zapiszMiejsca(VECM &);
void wczytajMiejsca(VECM &);
void pokazMiejsca(VECM &);
void wybierzMiejsce(void);
void dodajMiejsce(VECM &);
void usunMiejsce(VECM &);

void pokazElementyPociagow(VECP &);
void zapiszPociagi(VECP &);
void wczytajPociagi(VECP &);
void pokazPociagi(VECP &);
void wybierzPociag(void);
void dodajPociag(VECP &);
void usunPociag(VECP &);

void pokazElementyKursow(VECK &);
void zapiszKursy(VECK &);
void wczytajKursy(VECK &);
void pokazKursy(VECK &);
void wybierzKurs(void);
void dodajKurs(VECK &);
void usunKurs(VECK &);

void pokazMenu(void);
void obliczanieCzasu(int &, int &);
void wybierzBilet(void);
void pokazPodsumowanie(void);

#endif