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
    void setPociag(string, double);
    string getNazwa(void);
    double getPredkosc(void);
};

#endif