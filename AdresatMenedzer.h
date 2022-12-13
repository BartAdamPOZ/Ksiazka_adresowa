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

class AdresatMenedzer {
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int setIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int getIdOstatniegoAdresata();

};

#endif
