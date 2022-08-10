#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"

using namespace std;
class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    string wczytajLinie();
    char wczytajZnak();
    int wczytajLiczbeCalkowita();
    string konwerjsaIntNaString(int liczba);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);


public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
