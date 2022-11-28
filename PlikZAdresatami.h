#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "UzytkownikMenedzer.h"
#include "Adresat.h"
#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami = "Adresaci.txt";
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    vector <Adresat> adresaci;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    bool czyPlikJestPusty();

public:

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void dopiszAdresataDoPliku(Adresat adresat);
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
};

#endif
