#include <iostream>
#include <vector>
#include "../inc/miejsca.h"
#include "../inc/pociagi.h"
#include "../inc/tory.h"

using namespace std;

int main() {
    vector <Miejsce> myMiejsca;

    myMiejsca.push_back(Miejsce());
    myMiejsca[0].set_miejsce("Warszawa", 500);

    cout << myMiejsca[0].get_odleglosc();
    return 0;
}