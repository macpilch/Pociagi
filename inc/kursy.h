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
    int czas_podrozy;
    Godzina czas_wyjazdu;
    Godzina czas_przyjazdu;

    Kurs();
    Kurs(int, int, int);
    
    int get_numer(void);
    int get_czas_wyjazdu_godz(void);
    int get_czas_wyjazdu_min(void);
    void set_kurs(int, int, int);
    void obliczanie_czasu(int, int);
};

#endif