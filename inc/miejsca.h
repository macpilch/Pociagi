#ifndef _MIEJSCA_
#define _MIEJSCA_

#include <iostream>

using namespace std;

class Miejsce
{
private:
    string nazwa;
    double odleglosc;

public:
    Miejsce();
    void set_miejsce(string, double);
    string get_nazwa(void);
    double get_odleglosc(void);
};

#endif