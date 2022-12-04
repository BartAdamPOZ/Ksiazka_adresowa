#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "AdresatMenedzer.h"
#include "UzytkownikMenedzer.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    int idOstatniegoAdresata;
    const string nazwaPlikuZAdresatami;
    //string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    vector <Adresat> adresaci;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();

public:

    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI)
    {
        idOstatniegoAdresata = 0;
    };


    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();

};

#endif
