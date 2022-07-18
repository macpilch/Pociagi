/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: funkcje.h
    Data: 09.03.2022
    Modyfikacja: 19.07.2022
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

typedef vector<Miejsce> vecM;
typedef vector<Pociag> vecP;
typedef vector<Kurs> vecK;
typedef unsigned int uInt;

typedef struct {
    int ilosc;
    int nr;
} bilet;

void pokazElementyMiejsc(vecM &mM);
void zapiszMiejsce(vecM &mM);
void wczytajMiejsce(vecM &mM);
void pokazMiejsca(vecM &mM);
void wybierzMiejsce(void);
void dodajMiejsce(vecM &mM);
void usunMiejsce(vecM &mM);

void pokazElementyPociagow(vecP &mP);
void zapiszPociagi(vecP &mP);
void wczytajPociagi(vecP &mP);
void pokazPociagi(vecP &mP);
void wybierzPociag(void);
void dodajPociag(vecP &mP);
void usunPociag(vecP &mP);

void pokazElementyKursow(vecK &mK);
void zapiszKursy(vecK &mK);
void wczytajKursy(vecK &mK);
void pokazKursy(vecK &mK);
void wybierzKurs(void);
void dodajKurs(vecK &mK);
void usunKurs(vecK &mK);

void pokazMenu(void);
void obliczanieCzasu(void);
void wybierzBilet(void);
void pokazPodsumowanie(void);

#endif