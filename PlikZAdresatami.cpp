#include "PlikZAdresatami.h"


bool PlikZAdresatami :: dopiszAdresataDoPliku(Adresat adresat) {

    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), /*ios::out |*/ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata =  zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty()== true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami :: zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";


    liniaZDanymiAdresata += MetodyPomocnicze :: konwersjaIntNaString(adresat.pobierzIdAdresata()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze :: konwersjaIntNaString(adresat.pobierzIdUzytkownika())+ '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami :: pobierzZPlikuIdOstatniegoAdresata() {
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}

int PlikZAdresatami :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze :: konwersjaStringNaInt(MetodyPomocnicze ::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

vector <Adresat> PlikZAdresatami :: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {

    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }

    return adresaci;
}

Adresat PlikZAdresatami :: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawIdAdresata(MetodyPomocnicze::konwersjaStringNaInt(pojedynczaDanaAdresata));
                break;
            case 2:
                adresat.ustawIdUzytkownika(MetodyPomocnicze::konwersjaStringNaInt(pojedynczaDanaAdresata));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

void PlikZAdresatami :: usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami :: zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::edytujWybranegoAdresataWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out);

    bool czyPierwszaLinia = true;
    if (odczytywanyPlikTekstowy.good()) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            if (idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)) {
                if (!czyPierwszaLinia) {
                    tymczasowyPlikTekstowy << endl;
                }
                tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            } else {
                if (!czyPierwszaLinia) {
                    tymczasowyPlikTekstowy << endl;
                }
                tymczasowyPlikTekstowy << wczytanaLinia;
            }
            czyPierwszaLinia = false;
        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    } else {
        cout << "Nie uda³o siê otworzyæ pliku: " << NAZWA_PLIKU_Z_ADRESATAMI << endl;
    }
}

/*void PlikZAdresatami::edytujWybranegoAdresataWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";

    // Otwieranie plików
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if (!odczytywanyPlikTekstowy.is_open()) {
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_ADRESATAMI << endl;
        return;
    }

    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out);
    if (!tymczasowyPlikTekstowy.is_open()) {
        cout << "Nie udalo sie otworzyc pliku " << nazwaTymczasowegoPlikuZAdresatami << endl;
        odczytywanyPlikTekstowy.close();
        return;
    }

    bool czyPierwszaLinia = true;

    // Przetwarzanie pliku
    while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
        if (idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)) {
            if (!czyPierwszaLinia) {
                tymczasowyPlikTekstowy << endl;
            }
            tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            cout << "Zmieniono dane adresata na: " << liniaZDanymiAdresataOddzielonePionowymiKreskami << endl;
        } else {
            if (!czyPierwszaLinia) {
                tymczasowyPlikTekstowy << endl;
            }
            tymczasowyPlikTekstowy << wczytanaLinia;
            cout << "Przepisano linie: " << wczytanaLinia << endl;
        }
        czyPierwszaLinia = false;
    }

    // Zamkniêcie plików
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    // Operacje na plikach
    usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    cout << "Usunieto plik: " << NAZWA_PLIKU_Z_ADRESATAMI << endl;
    zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    cout << "Zmieniono nazwe pliku z: " << nazwaTymczasowegoPlikuZAdresatami << " na: " << NAZWA_PLIKU_Z_ADRESATAMI << endl;
}*/

/*void PlikZAdresatami :: zaktualizujDaneWybranegoAdresata(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    int idAdresata = 0;

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
    edytujWybranegoAdresataWPliku(idAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}*/

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    int idAdresata = adresat.pobierzIdAdresata(); // Pobierz rzeczywisty identyfikator adresata

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

    // SprawdŸ, czy istnieje adresat o podanym id
    if (idAdresata != 0) {
        edytujWybranegoAdresataWPliku(idAdresata, liniaZDanymiAdresata);
        cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
    } else {
        cout << "Nie ma takiego adresata do edycji." << endl << endl;
    }
}

void PlikZAdresatami :: usunWybranegoAdresataZPliku(int idUsuwanegoAdresata) {

    bool czyIstniejeAdresat = false;
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0) {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                czyIstniejeAdresat = true;
                continue;
            } else {
                if (czyIstniejeAdresat == false)
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                else
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    }
    else {
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
    }
}

