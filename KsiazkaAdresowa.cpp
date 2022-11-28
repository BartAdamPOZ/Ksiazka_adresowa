#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    metodyPomocnicze.wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku()
{
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

int KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    plikZAdresatami.wyswietlWszystkichAdresatow();
}
