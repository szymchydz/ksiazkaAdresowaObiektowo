#include "KsiazkaAdresowa.h"

using namespace std;

KsiazkaAdresowa :: KsiazkaAdresowa (){

uzytkownikMenedzer.wczytajUzytkownikowZPliku();

}

void KsiazkaAdresowa :: rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszUzytkownikow() {

    uzytkownikMenedzer.wypiszUzytkownikow();
}
