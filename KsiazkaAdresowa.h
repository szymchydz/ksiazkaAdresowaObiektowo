#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikMenedzer uzytkownikMenedzer;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wypiszUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
