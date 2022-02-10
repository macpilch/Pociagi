#ifndef _MIEJSCA_
#define _MIEJSCA_

#include <iostream>

using namespace std;

class Miejsce {
private:
    string nazwa;
    int odleglosc;
    bool stworzone;
public:
    Miejsce();
    void set_miejsce(string, int, bool);
    string get_nazwa(void);
    int get_odleglosc(void);
    bool get_stworzone(void);
};

#endif