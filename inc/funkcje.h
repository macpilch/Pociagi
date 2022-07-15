/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: funkcje.h
    Data: 09.03.2022
    Modyfikacja: 15.07.2022
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

typedef unsigned int uInt;

void pokazElementyMiejsc(vector<Miejsce> &mM);
void zapiszMiejsce(vector<Miejsce> &mM);
void wczytajMiejsce(vector<Miejsce> &mM);
void pokazMiejsca(vector<Miejsce> &mM);
void wybierzMiejsce(void);
void dodajMiejsce(vector<Miejsce> &mM);
void usunMiejsce(vector<Miejsce> &mM);

void pokazElementyPociagow(vector<Pociag> &mP);
void zapiszPociagi(vector<Pociag> &mP);
void wczytajPociagi(vector<Pociag> &mP);
void pokazPociagi(vector<Pociag> &mP);
void wybierzPociag(void);
void dodajPociag(vector<Pociag> &mP);
void usunPociag(vector<Pociag> &mP);

void pokazElementyKursow(vector<Kurs> &mK);
void zapiszKursy(vector<Kurs> &mK);
void wczytajKursy(vector<Kurs> &mK);
void pokazKursy(vector<Kurs> &mK);
void wybierzKurs(void);
void dodajKurs(vector<Kurs> &mK);
void usunKurs(vector<Kurs> &mK);

void pokazMenu(void);
void obliczanieCzasu(void);
void wybierzBilet(void);
void pokazPodsumowanie(void);

#endif