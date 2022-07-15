/*
    Projekt: Pociagi
    Autor: Maciej Pilch (z pomoca p. Krzysztofa Krupy)
    Plik: kursy.h
    Data: 20.01.2022
    Modyfikacja: 15.07.2022
*/

#ifndef __KURSY_H__
#define __KURSY_H__

struct Godzina {
    int min;
    int godz;
};

class Kurs {
public:
    double czasPodrozy;
    Godzina czasWyjazdu;
    Godzina czasPrzyjazdu;

    Kurs();
    ~Kurs();
    Kurs(int, int);
    void setKurs(int, int);
};

#endif