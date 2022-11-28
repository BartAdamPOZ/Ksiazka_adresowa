#include "AdresatMenedzer.h"

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    PlikZAdresatami plikZAdresatami;
    /*idOstatniegoAdresata = */plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika, idOstatniegoAdresata);
    //cout << "ID ostatniego adresata w klasie adresatmenedzer zwracanego bezposrednio do klasy ksiazka adresowa wynosi : " << idOstatniegoAdresata << endl;
    //Sleep (3000);
    //return idOstatniegoAdresata;
}

int AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    PlikZAdresatami plikZAdresatami;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    /*cout << "ID nastepnego adresata : " << adresat.pobierzId() << endl;
    cout << "ID zalogowanego uzytkownika : " << adresat.pobierzIdUzytkownika() << endl;
    Sleep (3000);*/

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

Adresat AdresatMenedzer::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.pobierzId() == atoi(pojedynczaDanaAdresata.c_str());
                //cout << "ID adresata pobranego z pliku: " <<  adresat.pobierzId() << endl;
                break;
            case 2:
                adresat.pobierzIdUzytkownika() == atoi(pojedynczaDanaAdresata.c_str());
                break;
            case 3:
                adresat.pobierzImie() = pojedynczaDanaAdresata;
                break;
            case 4:
                adresat.pobierzNazwisko() = pojedynczaDanaAdresata;
                break;
            case 5:
                adresat.pobierzNumerTelefonu() = pojedynczaDanaAdresata;
                break;
            case 6:
                adresat.pobierzEmail() = pojedynczaDanaAdresata;
                break;
            case 7:
                adresat.pobierzAdres() = pojedynczaDanaAdresata;
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int AdresatMenedzer::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    //cout << "To jest id ostaniego adresata z metody pobierzIdAdresataZDanychOddzielonymiPionowymiKreskami : " << idAdresata << endl;
    //Sleep (5000);
    return idAdresata;
}
