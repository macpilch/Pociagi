#ifndef _TORY_
#define _TORY_

class Tor
{
private:
    int numer;
    int poczatek;
    int koniec;

public:
    Tor();
    void set_tor(int, int, int);
    int get_numer(void);
    int get_poczatek(void);
    int get_koniec(void);
};

#endif