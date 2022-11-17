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
