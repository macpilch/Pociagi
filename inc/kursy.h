#ifndef _KURSY_
#define _KURSY_

struct Godzina {
    int min;
    int godz;
};

class Kurs {
public:
    double czasPodrozy;
    Godzina czasWyjazdu;
    Godzina czasPrzyjazdu;

    Kurs();
    Kurs(int, int);

    int getCzasWyjazduGodz(void);
    int getCzasWyjazduMin(void);
    void setKurs(int, int);
};

#endif