#ifndef _MIEJSCA_
#define _MIEJSCA_

#include <iostream>

using namespace std;

class Miejsce {
private:
    string nazwa;
    int odleglosc;
public:
    Miejsce();
    void set_miejsce(string, int);
    string get_nazwa(void);
    int get_odleglosc(void);
};

void add_miejsce();

#endif