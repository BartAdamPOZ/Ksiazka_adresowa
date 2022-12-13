#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.isUserLoggedIn()) {
        idZalogowanegoUzytkownika = adresatMenedzer.setIdZalogowanegoUzytkownika(uzytkownikMenedzer.getIdZalogowanegoUzytkownika());
        wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    }
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika) {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::getIdOstatniegoAdresata() {
    adresatMenedzer.getIdOstatniegoAdresata();
}
