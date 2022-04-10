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
    void setKurs(int, int);
};

#endif