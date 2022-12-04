#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    PlikZAdresatami plikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();

};

#endif
