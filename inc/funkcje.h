/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: funkcje.h
    Data: 09.03.2022
    Modyfikacja: 29.08.2022
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
    int nrMiejsca[MAX_BILETOW];
    int nrPociagu[MAX_BILETOW];
    int nrKursu[MAX_BILETOW];
} b;

void pokazElementyMiejsc(VECM &mM);
void zapiszMiejsca(VECM &mM);
void wczytajMiejsca(VECM &mM);
void pokazMiejsca(VECM &mM);
void wybierzMiejsce(void);
void dodajMiejsce(VECM &mM);
void usunMiejsce(VECM &mM);

void pokazElementyPociagow(VECP &mP);
void zapiszPociagi(VECP &mP);
void wczytajPociagi(VECP &mP);
void pokazPociagi(VECP &mP);
void wybierzPociag(void);
void dodajPociag(VECP &mP);
void usunPociag(VECP &mP);

void pokazElementyKursow(VECK &mK);
void zapiszKursy(VECK &mK);
void wczytajKursy(VECK &mK);
void pokazKursy(VECK &mK);
void wybierzKurs(void);
void dodajKurs(VECK &mK);
void usunKurs(VECK &mK);

void pokazMenu(void);
void obliczanieCzasu(void);
void wybierzBilet(void);
void pokazPodsumowanie(void);

#endif