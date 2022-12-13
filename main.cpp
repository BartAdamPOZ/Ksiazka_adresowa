#include <iostream>
#include <vector>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"
#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

using namespace std;

int main() {
    int idZalogowanegoUzytkownika = 0;
    char wybor;
    int idOstatniegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true) {
        if (idZalogowanegoUzytkownika == 0) {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            idOstatniegoAdresata = ksiazkaAdresowa.getIdOstatniegoAdresata();

            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1': //TO ZROBIC
                idOstatniegoAdresata = ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4': //TO ZROBIC
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //edytujAdresata(adresaci);
                break;
            case '7': //TO ZROBIC
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;
            case '8': //TO ZROBIC
                idZalogowanegoUzytkownika = 0;
                //adresaci.clear();
                break;
            }
        }
    }


    return 0;
}
