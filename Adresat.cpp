#include <iostream>
#include "Adresat.h"

using namespace std;

void Adresat :: ustawIdAdresata (int noweId) {
    if (noweId >= 0)
    idAdresata = noweId;
}

void Adresat :: ustawIdUzytkownika(int idZalogowanegoUzytkownika) {
    if (idZalogowanegoUzytkownika >= 0)
    idUzytkownika = idZalogowanegoUzytkownika;
}

void Adresat :: ustawImie(string noweImie) {
    imie = noweImie;
}

void Adresat :: ustawNazwisko(string noweNazwisko) {
    nazwisko = noweNazwisko;
}

void Adresat :: ustawNumerTelefonu(string nowyNumerTelefonu) {
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat :: ustawEmail(string nowyEmail) {
    email = nowyEmail;
}

void Adresat ::  ustawAdres(string nowyAdres) {
    adres = nowyAdres;
}

int Adresat :: pobierzIdAdresata() {
    return idAdresata;
}

int Adresat :: pobierzIdUzytkownika() {
    return idUzytkownika;
}

string Adresat :: pobierzImie() {
    return imie;
}

string Adresat :: pobierzNazwisko() {
    return nazwisko;
}

string Adresat :: pobierzNumerTelefonu() {
    return numerTelefonu;
}

string Adresat :: pobierzEmail() {
    return email;
}

string Adresat :: pobierzAdres() {
    return adres;
}
