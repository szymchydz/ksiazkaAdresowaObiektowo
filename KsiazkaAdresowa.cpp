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
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow() {

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresatMenedzer -> wyswietlWszystkichAdresatow();
    }
}

bool KsiazkaAdresowa :: czyUzytkownikJestZalogowany() {
    uzytkownikMenedzer.czyUzytkownikJestZalogowany();

}

void KsiazkaAdresowa :: wyszukajAdresatowPoImieniu() {

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresatMenedzer -> wyszukajAdresatowPoImieniu();
    } else {
        cout << "Aby wyszukac adresata po imieniu, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

void KsiazkaAdresowa :: wyszukajAdresatowPoNazwisku() {

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {

        adresatMenedzer -> wyszukajAdresatowPoNazwisku();
    } else {
        cout << "Aby dodac adresata po nazwisku, nalezy najpierw sie zalogowac" << endl;
        system ("pause");
    }
}

char KsiazkaAdresowa :: wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze :: wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa :: wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze :: wczytajZnak();

    return wybor;
}
