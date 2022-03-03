#ifndef _POCIAGI_
#define _POCIAGI_

#include <iostream>

using namespace std;

class Pociag {
private:
    string nazwa;
    int predkosc;
    int start;
public:
    void set_pociag_nazwa(string);
    void set_pociag_pred(int);
    string get_nazwa(void);
    int get_predkosc(void);
};

#endif