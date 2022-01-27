#include <iostream>
#include "../inc/miejsca.h"
#include "../inc/pociagi.h"
#include "../inc/tory.h"

using namespace std;

Miejsce miejsce[12];
Pociag pociag[10];

string nazwyMiast[12] = {
    "Warszawa", "Poznan", "Gdansk", "Krakow", "Lublin",
    "Wroclaw", "Gdynia", "Szczecin", "Lodz", "Bydgoszcz",
    "Kalisz", "Torun"
};

string nazwyPociagow[10] = {
    "Pendolino", "PKP Intercity", "", "", "",
    "", "", "", "", ""
};

int odleglosciMiast[12] = {
    336, 622, 625, 172, 181,
    436, 648, 812, 309, 511,
    385, 467
};

int predkosciPociagow[10] = {
    250, 160, 
};

void miejsce_init(void) {
    for(int i = 0; i < 12; i++) {
        miejsce[i].set_miejsce(nazwyMiast[i], odleglosciMiast[i]);
    }
}

int main() {
    miejsce_init();
    return 0;
}