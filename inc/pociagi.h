/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: pociagi.h
    Data: 20.01.2022
    Modyfikacja: 19.07.2022
*/

#ifndef __POCIAGI_H__
#define __POCIAGI_H__

#include <iostream>

using namespace std;

class Pociag {
private:
    string nazwa;
    double predkosc;

public:
    Pociag();
    ~Pociag();
    void setPociag(string, double);
    string getNazwa(void);
    double getPredkosc(void);
};

#endif