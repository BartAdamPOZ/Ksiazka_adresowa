#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    int idUsuwanegoAdresata;
    int idEdytowanegoAdresata;
    fstream plikTekstowy;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowy.txt";
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();

public:

    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };


    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int getIdOstatniegoAdresata();
    void setIdZalogowanegoUzytkownika (int idZalogowanegoUzytkownika);
    void setIdUsuwanegoAdresata (int idUsuwanegoAdresata);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    //int zwrocNumerLiniiSzukanegoAdresata(Adresat adresat);
    void edytujWybranaLinieWPliku(Adresat adresat);
};

#endif
