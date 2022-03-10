#ifndef _KURSY_
#define _KURSY_

struct Godzina
{
    int min;
    int godz;
};

class Kurs
{
public:
    int numer;
    double czas_podrozy;
    Godzina czas_wyjazdu;
    Godzina czas_przyjazdu;
    int odleglosc;

    Kurs();
    Kurs(int, Godzina, int);
    
    int get_numer(void);
};

#endif