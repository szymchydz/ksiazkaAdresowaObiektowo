#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {

    const string nazwaPlikuZAdresatami;
    int idOstatniegoAdresata;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);


public:
    PlikZAdresatami(string NAZWA_PLIKU_Z_ADRESATAMI) : nazwaPlikuZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI) {};
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzZPlikuIdOstatniegoAdresata();
};

#endif
