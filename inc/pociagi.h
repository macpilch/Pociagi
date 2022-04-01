#ifndef _POCIAGI_
#define _POCIAGI_

#include <iostream>

using namespace std;

class Pociag {
private:
    string nazwa;
    double predkosc;

public:
    Pociag();
    void setPociag(string, double);
    string getNazwa(void);
    double getPredkosc(void);
};

#endif