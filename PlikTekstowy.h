#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {

public:
    const string NAZWA_PLIKU;
    PlikTekstowy(const string& nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}
    bool czyPlikJestPusty();
};

#endif
