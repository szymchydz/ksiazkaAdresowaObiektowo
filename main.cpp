#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt"/*,"Adresaci.txt"*/);
    ksiazkaAdresowa.wypiszUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wylogowanieUzytkownika();




    return 0;
}
