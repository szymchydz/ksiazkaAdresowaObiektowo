#include "KsiazkaAdresowa.h"

using namespace std;

void KsiazkaAdresowa :: rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszUzytkownikow() {

    uzytkownikMenedzer.wypiszUzytkownikow();
}

int KsiazkaAdresowa :: logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika() {

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
