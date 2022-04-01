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
    double czas_podrozy;
    Godzina czas_wyjazdu;
    Godzina czas_przyjazdu;

    Kurs();
    Kurs(int, int);

    int get_czas_wyjazdu_godz(void);
    int get_czas_wyjazdu_min(void);
    void set_kurs(int, int);
};

#endif