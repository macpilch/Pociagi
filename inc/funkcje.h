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

void pokaz_elementy_miejsc(vector<Miejsce> &mm);
void zapisz_miejsce(vector<Miejsce> &mm);
void wczytaj_miejsce(vector<Miejsce> &mm);
void pokaz_miejsca(vector<Miejsce> &mm);
void wybierz_miejsce(void);
void dodaj_miejsce(vector<Miejsce> &mm);
void usun_miejsce(vector<Miejsce> &mm);

void pokaz_elementy_pociagow(vector<Pociag> &mp);
void zapisz_pociagi(vector<Pociag> &mp);
void wczytaj_pociagi(vector<Pociag> &mp);
void pokaz_pociagi(vector<Pociag> &mp);
void wybierz_pociag(void);
void dodaj_pociag(vector<Pociag> &mp);
void usun_pociag(vector<Pociag> &mp);

void pokaz_elementy_kursow(vector<Kurs> &mk);
void zapisz_kursy(vector<Kurs> &mk);
void wczytaj_kursy(vector<Kurs> &mk);
void pokaz_kursy(vector<Kurs> &mk);
void wybierz_kurs(void);
void dodaj_kurs(vector<Kurs> &mk);
void usun_kurs(vector<Kurs> &mk);

void pokaz_menu(void);
void obliczanie_czasu(void);
void pokaz_podsumowanie(void);

#endif