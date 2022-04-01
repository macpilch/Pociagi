#ifndef _MIEJSCA_
#define _MIEJSCA_

#include <iostream>

using namespace std;

class Miejsce {
private:
    string nazwa;
    double odleglosc;

public:
    Miejsce();
    void setMiejsce(string, double);
    string getNazwa(void);
    double getOdleglosc(void);
};

#endif