#include "KsiazkaAdresowa.h"

using namespace std;

void KsiazkaAdresowa :: rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszUzytkownikow() {
    uzytkownikMenedzer.wypiszUzytkownikow();
}

void KsiazkaAdresowa :: logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa :: wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: dodajAdresata() {

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresatMenedzer -> dodajAdresata();
    } else {
        cout << "Aby dodoac adresata, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow() {

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresatMenedzer -> wyswietlWszystkichAdresatow();
    }
}
