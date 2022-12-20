#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer.setIdZalogowanegoUzytkownika(uzytkownikMenedzer.getIdZalogowanegoUzytkownika());
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenedzer.getIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

bool KsiazkaAdresowa::wyloguj()
{
    return uzytkownikMenedzer.wyloguj();
}
