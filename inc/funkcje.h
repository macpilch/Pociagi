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

void pokaz_elementy_miejsc(vector<Miejsce> &mm, int *nr_m);
void zapisz_miejsce(vector<Miejsce> &mm, int *nr_m);
void wczytaj_miejsce(vector<Miejsce> &mm);
void pokaz_miejsca(vector<Miejsce> &mm, int *nr_m);
void dodaj_miejsce(vector<Miejsce> &mm, int *nr_m);
void usun_miejsce(vector<Miejsce> &mm, int *nr_m);

void pokaz_elementy_pociagow(vector<Pociag> &mp, int *nr_p);
void zapisz_pociagi(vector<Pociag> &mp, int *nr_p);
void wczytaj_pociagi(vector<Pociag> &mp);
void pokaz_pociagi(vector<Pociag> &mp, int *nr_p);
void dodaj_pociag(vector<Pociag> &mp, int *nr_p);
void usun_pociag(vector<Pociag> &mp, int *nr_p);

void pokaz_elementy_kursow(vector<Kurs> &mk, int *nr_k);
void zapisz_kursy(vector<Kurs> &mk, int *nr_k);
void wczytaj_kursy(vector<Kurs> &mk);
void pokaz_kursy(vector<Kurs> &mk, int *nr_k);
void dodaj_kurs(vector<Kurs> &mk, int *nr_k);
void usun_kurs(vector<Kurs> &mk, int *nr_k);

void pokaz_menu(void);
void obliczanie_czasu(void);
void pokaz_podsumowanie(void);

#endif