#ifndef __KURSY_H__
#define __KURSY_H__

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