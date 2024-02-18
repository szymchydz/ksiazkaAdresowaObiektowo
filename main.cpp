#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();

    return 0;
}
