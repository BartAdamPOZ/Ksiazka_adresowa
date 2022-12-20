#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <sstream>

#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"



using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    int idZalogowanegoUzytkownika = 0;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    bool wyloguj();
};

#endif
