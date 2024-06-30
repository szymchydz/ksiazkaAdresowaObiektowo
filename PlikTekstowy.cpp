#include "PlikTekstowy.h"


bool PlikTekstowy :: czyPlikJestPusty() {

    fstream plikTekstowy(nazwaPliku, ios::in);

    if (!plikTekstowy.is_open()) {
        cerr << "Blad otwarcia pliku!" << endl;
        return false;
    }

    plikTekstowy.seekg(0, ios::end);
    bool isEmpty = (plikTekstowy.tellg() == 0);
    plikTekstowy.close();
    return isEmpty;

 }
