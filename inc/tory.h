#ifndef _TORY_
#define _TORY_

class Tor {
private:
    int poczatek;
    int koniec;
    bool dostepnosc;
public:
    void set_poczatek(int);
    int get_poczatek(void);
    int get_koniec(void);
    bool get_dostepnosc(void);
};

#endif