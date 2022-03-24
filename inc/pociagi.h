#ifndef _POCIAGI_
#define _POCIAGI_

#include <iostream>

using namespace std;

class Pociag
{
private:
    string nazwa;
    int predkosc;

public:
    Pociag();
    void set_pociag(string, int);
    string get_nazwa(void);
    int get_predkosc(void);
};

#endif