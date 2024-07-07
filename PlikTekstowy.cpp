#include "PlikTekstowy.h"


bool PlikTekstowy :: czyPlikJestPusty() {

    fstream plikTekstowy(NAZWA_PLIKU, ios::in);

    if (!plikTekstowy.is_open()) {
        cerr << "Blad otwarcia pliku!" << endl;
        return false;
    }

    plikTekstowy.seekg(0, ios::end);
    bool isEmpty = (plikTekstowy.tellg() == 0);
    plikTekstowy.close();
    return isEmpty;

 }
