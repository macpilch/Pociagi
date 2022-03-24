#ifndef _FUNKCJE_
#define _FUNKCJE_

#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <conio.h>

#include "../inc/miejsca.h"
#include "../inc/pociagi.h"
#include "../inc/kursy.h"

int nr_miejsca;
int nr_pociagu;
int nr_kursu;

vector<Miejsce> myMiejsca;
vector<Pociag> myPociagi;
vector<Kurs> myKursy;

void pokaz_menu(void);
void pokaz_elementy_miejsc(void);
void zapisz_miejsce(void);
void wczytaj_miejsce(void);
void pokaz_miejsca(void);
void dodaj_miejsce(void);
void usun_miejsce(void);
void pokaz_elementy_pociagow(void);
void zapisz_pociagi(void);
void wczytaj_pociagi(void);
void pokaz_pociagi(void);
void dodaj_pociag(void);
void usun_pociag(void);
void pokaz_elementy_kursow(void);
void zapisz_kursy(void);
void wczytaj_kursy(void);
void pokaz_kursy(void);
void dodaj_kurs(void);
void usun_kurs(void);
void pokaz_podsumowanie(void);

#endif