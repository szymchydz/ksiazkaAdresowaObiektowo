#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {

    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt","Adresaci.txt");

    ksiazkaAdresowa.wypiszUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogowanieUzytkownika();



    //ksiazkaAdresowa.rejestracjaUzytkownika();

    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();





    return 0;
}
