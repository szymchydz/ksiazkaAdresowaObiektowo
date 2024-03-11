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

void KsiazkaAdresowa :: wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
