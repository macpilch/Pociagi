#ifndef _POCIAGI_
#define _POCIAGI_

#include <iostream>

using namespace std;

class Pociag {
private:
    string nazwa;
    int predkosc;
    bool dostepnosc;
    int start;
public:
    void set_pociag_nazwa(string);
    void set_pociag_pred(int);
    void set_pociag_dost(bool);
    string get_nazwa(void);
    int get_predkosc(void); 
    bool get_dostepnosc(void);
};

void pociagi_init(void);

#endif