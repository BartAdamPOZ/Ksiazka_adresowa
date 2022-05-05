#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Friend {
    string friendName, friendSurname, friendAddress, friendMail;
    int phoneNumber, friendId, ownerId;
};

struct Uzytkownik {
    int idUzytkownika;
    string nazwa, haslo;
};

void displayDataAboutFriend(vector<Friend> &friends, int i) {
    cout << "Imie i nazwisko: " << friends[i].friendName << " ";
    cout << friends[i].friendSurname << endl;
    cout << "Telefon: " << friends[i].phoneNumber << endl;
    cout << "E-mail: " << friends[i].friendMail << endl;
    cout << "Adres: " << friends[i].friendAddress << endl;
    cout << endl;
}

void searchByName (vector <Friend> friends) {

    Friend myFriend;
    string nameToSearch;

    cout << "Wprowadz imie szukanego znajomego: ";
    cin >> nameToSearch;

    for (int i = 0; i < friends.size(); i++) {
        if (nameToSearch == friends[i].friendName)
            displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}

void searchBySurname (vector <Friend> friends) {

    Friend myFriend;
    string surnameToSearch;

    cout << "Wprowadz nazwisko szukanego znajomego: ";
    cin >> surnameToSearch;

    for (int i = 0; i < friends.size(); i++) {
        if (surnameToSearch == friends[i].friendSurname)
            displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}

void deleteAllDataInFile() {

    fstream file;
    file.open("Adresaci_uzytkownika.txt",ios::trunc| ios::in | ios::out);
    file.close();

}

void saveDataToFile (vector <Friend> &friends) {

    fstream file;
    Friend myFriend;

    file.open("Adresaci_uzytkownika.txt",ios::out | ios:: app);


    for (int i = 0; i < friends.size(); i++) {

        file << friends[i].friendId << "|";
        file << friends[i].ownerId << "|";
        file << friends[i].friendName << "|";
        file << friends[i].friendSurname << "|";
        file << friends[i].phoneNumber << "|";
        file << friends[i].friendMail << "|";
        file << friends[i].friendAddress<< "|" << endl;
    }

    file.close();
    friends.shrink_to_fit();
}

void deleteFriendFromList (vector <Friend> &friends) {

    Friend myFriend;
    int idToDelete;
    char choice;
    bool foundOrNot = false;

    do {
        cout << "Wprowadz ID znajomego, ktorego chcesz usunac: ";
        cin >> idToDelete;

        for (int i = 0; i < friends.size(); i++) {
            if (idToDelete == friends[i].friendId) {
                foundOrNot = true;
                displayDataAboutFriend(friends, i);
            }
        }
        if (foundOrNot == false)
            cout << "Bledne dane. Sprobuj ponownie." << endl;

    } while (foundOrNot == false);

    cout << "Czy napewno chcesz usunac tego znajomego? t(tak)/n(nie): ";
    cin >> choice;
    if (choice == 't') {
        for (int i = 0; i < friends.size(); i++) {
            if (idToDelete == friends[i].friendId) {
                auto it = friends.begin() + i;
                friends.erase(it);
                deleteAllDataInFile();
                saveDataToFile(friends);
                cout << "Pomyslnie usunieto znajomego." << endl;
                Sleep(2000);
            }
        }
    }
    friends.shrink_to_fit();
}

void editData (vector <Friend> &friends, int idOfFriendToEdit, char dataToEdit) {

    string name, surname, address, mail;
    int phone;
    Friend myFriend;

    cout << "Wprowadz nowe dane: ";

    if (dataToEdit == '1') {

        cin >> name;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendName = name;
            }
        }
    } else if (dataToEdit == '2') {

        cin >> surname;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendSurname = surname;
            }
        }
    } else if (dataToEdit == '3') {

        cin >> phone;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].phoneNumber = phone;
            }
        }
    } else if (dataToEdit == '4') {

        cin >> mail;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendMail = mail;
            }
        }
    } else if (dataToEdit == '5') {

        cin.sync();
        getline(cin,address);

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendAddress = address;
            }
        }
    }
    deleteAllDataInFile();
    saveDataToFile(friends);
    cout << "Pomyslanie zmieniono dane znajomego." << endl;
    Sleep(2000);
}

void editDataAboutFriend (vector<Friend> &friends) {

    char choice;
    int idOfFriendToEdit;
    bool foundOrNot = false;

    do {
        cout << "Wprowadz ID znajomego, ktorego dane chcesz edytowac: ";
        cin >> idOfFriendToEdit;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                foundOrNot = true;
            }
        }
        if (foundOrNot == false)
            cout << "Bledne dane. Sprobuj ponownie." << endl;

    } while (foundOrNot == false);

    do {
        if(1) {
            system("cls");
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Numer telefonu" << endl;
            cout << "4. Email" << endl;
            cout << "5. Adres" << endl;
            cout << "6. Powrot do menu" << endl;
            cout << "7. Zakoncz program" << endl;
            cin >> choice;

            if (choice == '1') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '2') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '3') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '4') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '5') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '6') {
            }
            friends.shrink_to_fit();
        }
    } while (0);
}


void displayFriendsList(vector<Friend> &friends) {

    for (int i = 0; i < friends.size(); i++) {
        displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}

/*void readDataFromFile (vector <Friend> &friends) {

    Friend myFriend;

    fstream file;
    file.open("Ksiazka_adresowa.txt", ios::out | ios:: app);
    file.close();

    file.open("Ksiazka_adresowa.txt", ios::in);

    if(file.good() == false) {
        cout << "Plik nie istnieje!";
        exit(0);
    }

    string line;
    int item = 1;

    while (getline (file, line, '|')) {
        switch (item) {
        case 1:
            myFriend.friendId = atoi(line.c_str());
            break;
        case 2:
            myFriend.ownerId = atoi(line.c_str());
            break;
        case 3:
            myFriend.friendName = line;
            break;
        case 4:
            myFriend.friendSurname = line;
            break;
        case 5:
            myFriend.phoneNumber = atoi(line.c_str());
            break;
        case 6:
            myFriend.friendMail = line;
            break;
        case 7:
            myFriend.friendAddress = line;
            break;
        }
        if(item == 7) {
            item = 1;
            friends.push_back(myFriend);
        } else {
            item++;
        }
    }
    file << endl;
    file.close();
}*/

void addNewFriend (vector <Friend> &friends, vector <Uzytkownik> uzytkownicy, int &idZalogowanegoUzytkownika, int &ostatnieIdAdresata) {
    string name, surname, address, mail;
    int phone, id;
    Friend myFriend;
    Uzytkownik mojUzytkownik;

    cout << "Dodaj swojego znajomego! Wprowadz dane ponizej: " << endl;

    cout << "Imie: ";
    cin >> name;
    cout << "Nazwisko: ";
    cin >> surname;
    cout << "mail: ";
    cin >> mail;
    cout << "telefon: ";
    cin >> phone;
    cout << "Adres: ";
    cin.sync();
    getline(cin, address);

    if (friends.size() == 0) {
        id = 1;
    } else {
        id = ostatnieIdAdresata + 1;
    }

    myFriend.friendId = id;
    myFriend.ownerId = idZalogowanegoUzytkownika;
    myFriend.friendName = name;
    myFriend.friendSurname = surname;
    myFriend.friendAddress = address;
    myFriend.friendMail = mail;
    myFriend.phoneNumber = phone;

    friends.push_back(myFriend);
    cout << "Pomyslnie dodano znajomego!";
    Sleep(2000);

    fstream file;
    file.open("Adresaci_uzytkownika.txt",ios::out | ios:: app);


    file << id << "|";
    file << idZalogowanegoUzytkownika << "|";
    file << name << "|";
    file << surname<< "|";
    file << phone << "|";
    file << mail << "|";
    file << address<< "|" << endl;

    file.close();
    ostatnieIdAdresata++;
}

/* z drugiego programu */

int rejestracja(vector <Uzytkownik> &uzytkownicy,int iloscUzytkownikow) {
    Uzytkownik mojUzytkownik;
    string nazwa, haslo;
    int idUzytkownika = iloscUzytkownikow +1;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;

    int i = 0;
    while (i < iloscUzytkownikow) {
        if (uzytkownicy[i].nazwa == nazwa) {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> nazwa;
            i = -1;
        } else {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> haslo;
    mojUzytkownik.nazwa = nazwa;
    mojUzytkownik.haslo = haslo;
    mojUzytkownik.idUzytkownika = uzytkownicy[uzytkownicy.size() - 1].idUzytkownika + 1 ;
    uzytkownicy.push_back(mojUzytkownik);
    cout << "Konto zalozone" << endl;
    Sleep(1000);

    fstream file;
    file.open("Uzytkownicy.txt",ios::out | ios:: app);


    file << idUzytkownika << "|";
    file << nazwa << "|";
    file << haslo<< "|" << endl;

    file.close();

    return iloscUzytkownikow+1;
}

int logowanie(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow) {
    Uzytkownik mojUzytkownik;
    string nazwa, haslo;
    cout << "Podaj nazwe: ";
    cin >> nazwa;
    int i = 0;
    while (i < iloscUzytkownikow) {
        if (uzytkownicy[i].nazwa == nazwa) {
            for(int proby = 0; proby < 3; proby++) {
                cout << "Podaj haslo. Pozostalo prob " << 3 - proby << ": ";
                cin >> haslo;
                if(uzytkownicy[i].haslo == haslo) {
                    cout << "Zalogowales sie." << endl;
                    //cout << "Twoje id Uzytkownika to: " << uzytkownicy[i].idUzytkownika << endl;
                    Sleep(1000);
                    return uzytkownicy[i].idUzytkownika;
                }
            }
            cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba" << endl;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl;
    Sleep(1500);
    return 0;

}

void zmianaHasla(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow, int idZalogowanegoUzytkownika) {

    Uzytkownik mojUzytkownik;
    string haslo;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;
    for (int i = 0; i < iloscUzytkownikow; i++) {
        if(uzytkownicy[i].idUzytkownika == idZalogowanegoUzytkownika) {
            uzytkownicy[i].haslo = haslo;
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(1500);
        }
    }
}

/* z drugiego programu */

/* nowe modyfikacje */

void wczytajDaneZplikuUzytkownicy(vector <Uzytkownik> &uzytkownicy, int &iloscUzytkownikow) {

    Uzytkownik mojUzytkownik;

    fstream file;
    file.open("Uzytkownicy.txt", ios::out | ios:: app);
    file.close();

    file.open("Uzytkownicy.txt", ios::in);

    if(file.good() == false) {
        cout << "Plik nie istnieje!";

        exit(0);
    }

    string line;
    int item = 1;

    while (getline (file, line, '|')) {
        switch (item) {
        case 1:
            mojUzytkownik.idUzytkownika = atoi(line.c_str());
            break;
        case 2:
            mojUzytkownik.nazwa = line;
            break;
        case 3:
            mojUzytkownik.haslo = line;
            break;
        }
        if(item == 3) {
            item = 1;
            uzytkownicy.push_back(mojUzytkownik);
            iloscUzytkownikow++;
        } else {
            item++;
        }
    }
    file << endl;
    file.close();
}

bool sprawdzCzyToAdresatUzytkownika (int AKTUALNE_ID_DO_SPRAWDZENIA, int idZalogowanegoUzytkownika) {
    if (AKTUALNE_ID_DO_SPRAWDZENIA == idZalogowanegoUzytkownika)
        return true;
    else
        return false;
}

void wyodrebnijAdresatowZalogowanegoUzytkownika (vector <Friend> &friends, int idZalogowanegoUzytkownika, int &ostatnieIdAdresata) {

    Friend myFriend;

    fstream file;
    file.open("Ksiazka_adresowa.txt", ios::out | ios:: app);
    file.close();

    if(file.good() == false) {
        cout << "Plik nie istnieje!";
        exit(0);
    }

    file.open("Ksiazka_adresowa.txt", ios::in);

    string line;
    int item = 1;

    while (getline (file, line, '|')) {
        switch (item) {
        case 1:
            myFriend.friendId = atoi(line.c_str());
            break;
        case 2:
            myFriend.ownerId = atoi(line.c_str());
            break;
        case 3:
            myFriend.friendName = line;
            break;
        case 4:
            myFriend.friendSurname = line;
            break;
        case 5:
            myFriend.phoneNumber = atoi(line.c_str());
            break;
        case 6:
            myFriend.friendMail = line;
            break;
        case 7:
            myFriend.friendAddress = line;
            break;
        }
        if(item == 7) {
            item = 1;
            int AKTUALNE_ID_DO_SPRAWDZENIA = myFriend.ownerId;
            ostatnieIdAdresata = myFriend.friendId;

            if (sprawdzCzyToAdresatUzytkownika(AKTUALNE_ID_DO_SPRAWDZENIA, idZalogowanegoUzytkownika) == true) {
                friends.push_back(myFriend);
            }
        } else {
            item++;
        }
    }
    file << endl;
    file.close();
    saveDataToFile(friends);
}

void zresetujAdresatow (vector <Friend> &friends, int &iloscUzytkownikow) {

    Friend myFriend;

    fstream file;
    file.open("Adresaci_uzytkownika.txt", ios::out | ios::trunc);
    file.close();

    friends.clear();
}

void synchronizujKsiazkeAdresatow(vector <Friend> &friends) {

    Friend myFriend;
    string friendNameTemporary, friendSurnameTemporary, friendAddressTemporary, friendMailTemporary;
    int phoneNumberTemporary, friendIdTemporary, ownerIdTemporary;

    getch(); //pozniej do usuniecia
    fstream file;
    file.open("Ksiazka_adresowa.txt", ios::out | ios::app );
    file.close();

    fstream file2;
    file2.open("Ksiazka_adresowa_tymczasowa.txt", ios::out | ios::app );
    file2.close();

    string line;
    int item = 1;
    int i = 0;

    file.open("Ksiazka_adresowa.txt", ios::in);
    file2.open("Ksiazka_adresowa_tymczasowa.txt", ios::out | ios::app );

    while (getline (file, line, '|')) {
        switch (item) {
        case 1:
            friendIdTemporary = atoi(line.c_str());
            break;
        case 2:
            ownerIdTemporary = atoi(line.c_str());
            break;
        case 3:
            friendNameTemporary = line;
            break;
        case 4:
            friendSurnameTemporary = line;
            break;
        case 5:
            phoneNumberTemporary = atoi(line.c_str());
            break;
        case 6:
            friendMailTemporary = line;
            break;
        case 7:
            friendAddressTemporary = line;
            break;
        }
        if(item == 7) {
            item = 1;

            if (friends[i].friendId == friendIdTemporary) {

                file2 << friends[i].friendId << "|";
                file2 << friends[i].ownerId << "|";
                file2 << friends[i].friendName << "|";
                file2 << friends[i].friendSurname<< "|";
                file2 << friends[i].phoneNumber << "|";
                file2 << friends[i].friendMail << "|";
                file2 << friends[i].friendAddress<< "|" << endl;
                displayDataAboutFriend(friends, i);
                getch();
                auto it = friends.begin() + i;
                friends.erase(it);
            } else {
                file2 << friendIdTemporary << "|";
                file2 << ownerIdTemporary << "|";
                file2 << friendNameTemporary << "|";
                file2 << friendSurnameTemporary << "|";
                file2 << phoneNumberTemporary << "|";
                file2 << friendMailTemporary << "|";
                file2 << friendAddressTemporary << "|" << endl;
            }
        } else {
            item++;
        }
    }
    for(int j = 0; j < friends.size(); j++) {
            file2 << friends[j].friendId << "|";
            file2 << friends[j].ownerId << "|";
            file2 << friends[j].friendName << "|";
            file2 << friends[j].friendSurname<< "|";
            file2 << friends[j].phoneNumber << "|";
            file2 << friends[j].friendMail << "|";
            file2 << friends[j].friendAddress<< "|" << endl;
        }
    file2.close();
    file.close();
    remove("Ksiazka_adresowa.txt");
    rename("Ksiazka_adresowa_tymczasowa.txt", "Ksiazka_adresowa.txt");
}

/*nowe modyfikacje*/


int main() {
    char choice = 0;
    vector<Friend> friends;

    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika = 0;
    int iloscUzytkownikow = 0;
    int ostatnieIdAdresata = 0;

    char wybor;

    wczytajDaneZplikuUzytkownicy(uzytkownicy, iloscUzytkownikow);


    while(1) {
        if(idZalogowanegoUzytkownika == 0) {
            system("cls");
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cin >> wybor;

            if (wybor == '1') {
                iloscUzytkownikow = rejestracja(uzytkownicy,iloscUzytkownikow);
            } else if (wybor == '2') {
                idZalogowanegoUzytkownika = logowanie(uzytkownicy, iloscUzytkownikow);
                wyodrebnijAdresatowZalogowanegoUzytkownika(friends, idZalogowanegoUzytkownika, ostatnieIdAdresata);
            } else if (wybor == '9') {
                exit(0);
            }
        } else {
            system("cls");
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            //cout << "9. Zakoncz program" << endl;//
            cin >> choice;

            if (choice == '1') {
                addNewFriend(friends, uzytkownicy,idZalogowanegoUzytkownika, ostatnieIdAdresata);
            } else if (choice == '2') {
                searchByName(friends);
            } else if (choice == '3') {
                searchBySurname(friends);
            } else if (choice == '4') {
                displayFriendsList(friends);
            } else if (choice == '5') {
                deleteFriendFromList(friends);
            } else if (choice == '6') {
                editDataAboutFriend(friends);
            } /*else if (choice == '9') {
                exit(0);
            }*/
            else if (choice == '7') { /* z drugiego programu*/
                zmianaHasla(uzytkownicy, iloscUzytkownikow, idZalogowanegoUzytkownika);
            } else if (choice == '8') { /* z drugiego programu*/
                synchronizujKsiazkeAdresatow (friends);
                zresetujAdresatow (friends, iloscUzytkownikow);
                idZalogowanegoUzytkownika = 0;
            }
        }
    }
    return 0;
}

