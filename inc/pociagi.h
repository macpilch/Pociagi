#ifndef _POCIAGI_
#define _POCIAGI_

#include <iostream>

using namespace std;

class Pociag
{
private:
    string nazwa;
    double predkosc;

public:
    Pociag();
    void set_pociag(string, double);
    string get_nazwa(void);
    double get_predkosc(void);
};

#endif