#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.wypiszUzytkownikow();



    return 0;
}
