/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: miejsca.h
    Data: 20.01.2022
    Modyfikacja: 23.07.2022
*/

#ifndef __MIEJSCA_H__
#define __MIEJSCA_H__

#include <iostream>

using namespace std;

class Miejsce {
private:
    string nazwa;
    double odleglosc;

public:
    Miejsce();
    ~Miejsce();
    void setMiejsce(string, double);
    string getNazwa(void);
    double getOdleglosc(void);
};

#endif