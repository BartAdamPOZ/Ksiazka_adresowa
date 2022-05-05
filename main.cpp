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

struct User {
    int userId;
    string login, password;
};

void clearFileWithUserRecipients () {

    fstream file;
    file.open("Adresaci_uzytkownika.txt", ios::out | ios::trunc);
    file.close();
}

void displayDataAboutFriend(vector<Friend> friends, int i) {
    cout << "Imie i nazwisko: " << friends[i].friendName << " ";
    cout << friends[i].friendSurname << endl;
    cout << "Telefon: " << friends[i].phoneNumber << endl;
    cout << "E-mail: " << friends[i].friendMail << endl;
    cout << "Adres: " << friends[i].friendAddress << endl;
    cout << endl;
}

void searchByName (vector <Friend> friends) {

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

void saveDataToFile_Adresaci_uzytkownika (vector <Friend> friends) {

    fstream file;

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

void saveDataToFile_Uzytkownicy (vector <User> users, int totalNumberOfUsers) {

    fstream file;

    file.open("Uzytkownicy.txt", ios::out | ios::trunc);
    file.close();

    file.open("Uzytkownicy.txt",ios::out | ios:: app);


    for (int i = 0; i < users.size(); i++) {

        file << users[i].userId << "|";
        file << users[i].login << "|";
        file << users[i].password << "|";
        file << endl;
    }

    file.close();
    users.shrink_to_fit();
}

void deleteFriendFromList (vector <Friend> &friends) {

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
                saveDataToFile_Adresaci_uzytkownika(friends);
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

    cout << "Wprowadz nowe dane: ";

    switch (dataToEdit) {
    case 1:
        cin >> name;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendName = name;
            }
        }
        break;
    case 2:
        cin >> surname;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendSurname = surname;
            }
        }
        break;
    case 3:
        cin >> phone;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].phoneNumber = phone;
            }
        }
        break;
    case 4:
        cin >> mail;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendMail = mail;
            }
        }
        break;
    case 5:
        cin.sync();
        getline(cin,address);

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendAddress = address;
            }
        }
        break;
    }

    deleteAllDataInFile();
    saveDataToFile_Adresaci_uzytkownika(friends);
    cout << "Pomyslanie zmieniono dane znajomego." << endl;
    Sleep(2000);
}

void editDataAboutFriend (vector<Friend> &friends) {

    int item;
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
            cin >> item;

            switch(item) {
            case 1:
                editData(friends, idOfFriendToEdit, item);
                break;
            case 2:
                editData(friends, idOfFriendToEdit, item);
                break;
            case 3:
                editData(friends, idOfFriendToEdit, item);
                break;
            case 4:
                editData(friends, idOfFriendToEdit, item);
                break;
            case 5:
                editData(friends, idOfFriendToEdit, item);
                break;
            case 6:
                break;
            }
            friends.shrink_to_fit();
        }
    } while (0);
}


void displayFriendsList(vector<Friend> friends) {

    for (int i = 0; i < friends.size(); i++) {
        displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}


int addNewFriend (vector <Friend> &friends, int loggedInUserId, int lastRecipientId) {
    string name, surname, address, mail;
    int phone, id;
    Friend myFriend;

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
        id = lastRecipientId + 1;
    }

    myFriend.friendId = id;
    myFriend.ownerId = loggedInUserId;
    myFriend.friendName = name;
    myFriend.friendSurname = surname;
    myFriend.friendAddress = address;
    myFriend.friendMail = mail;
    myFriend.phoneNumber = phone;

    friends.push_back(myFriend);
    cout << "Pomyslnie dodano znajomego!";
    Sleep(2000);

    clearFileWithUserRecipients();
    saveDataToFile_Adresaci_uzytkownika(friends);

    lastRecipientId++;

    return lastRecipientId;
}

int registration(vector <User> &users,int totalNumberOfUsers) {
    User signedInUser;
    string login, password;
    int userId = totalNumberOfUsers +1;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;

    int i = 0;
    while (i < totalNumberOfUsers) {
        if (users[i].login == login) {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> login;
            i = -1;
        } else {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> password;
    signedInUser.login = login;
    signedInUser.password = password;
    signedInUser.userId = userId;
    users.push_back(signedInUser);
    cout << "Konto zalozone" << endl;
    Sleep(1000);

    fstream file;
    file.open("Uzytkownicy.txt",ios::out | ios:: app);


    file << userId << "|";
    file << login << "|";
    file << password<< "|" << endl;

    file.close();

    return totalNumberOfUsers+1;
}

int signIn(vector <User> &users, int totalNumberOfUsers) {
    string login, password;
    cout << "Podaj nazwe: ";
    cin >> login;
    int i = 0;
    while (i < totalNumberOfUsers) {
        if (users[i].login == login) {
            for(int attempt = 0; attempt < 3; attempt++) {
                cout << "Podaj haslo. Pozostalo prob " << 3 - attempt << ": ";
                cin >> password;
                if(users[i].password == password) {
                    cout << "Zalogowano." << endl;
                    Sleep(1000);
                    return users[i].userId;
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

void changePassword(vector <User> &users, int totalNumberOfUsers, int loggedInUserId) {

    string password;
    cout << "Podaj nowe haslo: ";
    cin >> password;
    for (int i = 0; i < totalNumberOfUsers; i++) {
        if(users[i].userId == loggedInUserId) {
            users[i].password = password;
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(1500);
            saveDataToFile_Uzytkownicy(users, totalNumberOfUsers);
        }
    }
}

void loadDataFromFile_Uzytkownicy(vector <User> &users, int &totalNumberOfUsers) {

    User signedInUser;

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
            signedInUser.userId = atoi(line.c_str());
            break;
        case 2:
            signedInUser.login = line;
            break;
        case 3:
            signedInUser.password = line;
            break;
        }
        if(item == 3) {
            item = 1;
            users.push_back(signedInUser);
            totalNumberOfUsers++;
        } else {
            item++;
        }
    }
    file << endl;
    file.close();
}

bool checkRecipientOwner (int ACTUAL_ID_TO_CHECK, int loggedInUserId) {
    if (ACTUAL_ID_TO_CHECK == loggedInUserId)
        return true;
    else
        return false;
}

int getOnlyLoggedInUserRecipients (vector <Friend> &friends, int loggedInUserId, int lastRecipientId) {

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
            int ACTUAL_ID_TO_CHECK = myFriend.ownerId;
            lastRecipientId = myFriend.friendId;

            if (checkRecipientOwner(ACTUAL_ID_TO_CHECK, loggedInUserId) == true) {
                friends.push_back(myFriend);
            }
        } else {
            item++;
        }
    }
    file << endl;
    file.close();
    saveDataToFile_Adresaci_uzytkownika(friends);

    return lastRecipientId;
}

void dataSynchronization(vector <Friend> &friends) {

    Friend myFriend;
    string friendNameTemporary, friendSurnameTemporary, friendAddressTemporary, friendMailTemporary;
    int phoneNumberTemporary, friendIdTemporary, ownerIdTemporary;

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

            if (friends[i].ownerId != ownerIdTemporary) {

                file2 << friendIdTemporary << "|";
                file2 << ownerIdTemporary << "|";
                file2 << friendNameTemporary << "|";
                file2 << friendSurnameTemporary << "|";
                file2 << phoneNumberTemporary << "|";
                file2 << friendMailTemporary << "|";
                file2 << friendAddressTemporary << "|" << endl;

            } else if (friends[i].friendId == friendIdTemporary) {
                file2 << friends[i].friendId << "|";
                file2 << friends[i].ownerId << "|";
                file2 << friends[i].friendName << "|";
                file2 << friends[i].friendSurname<< "|";
                file2 << friends[i].phoneNumber << "|";
                file2 << friends[i].friendMail << "|";
                file2 << friends[i].friendAddress<< "|" << endl;
                auto it = friends.begin() + i;
                friends.erase(it);
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

int main() {

    char choice = 0;
    vector<Friend> friends;
    vector<User> users;
    int loggedInUserId = 0;
    int totalNumberOfUsers = 0;
    int lastRecipientId = 0;
    int item;

    loadDataFromFile_Uzytkownicy(users, totalNumberOfUsers);

    while(1) {
        if(loggedInUserId == 0) {
            system("cls");
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cin >> item;

            switch (item) {
            case 1:
                totalNumberOfUsers = registration(users,totalNumberOfUsers);
                break;
            case 2:
                loggedInUserId = signIn(users, totalNumberOfUsers);
                lastRecipientId = getOnlyLoggedInUserRecipients(friends, loggedInUserId, lastRecipientId);
                break;
            case 9:
                exit(0);
                break;
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
            cin >> item;

            switch (item) {
            case 1:
                lastRecipientId = addNewFriend(friends,loggedInUserId, lastRecipientId);
                break;
            case 2:
                searchByName(friends);
                break;
            case 3:
                searchBySurname(friends);
                break;
            case 4:
                displayFriendsList(friends);
                break;
            case 5:
                deleteFriendFromList(friends);
                break;
            case 6:
                editDataAboutFriend(friends);
                break;
            case 7:
                changePassword(users, totalNumberOfUsers, loggedInUserId);
                break;
            case 8:
                dataSynchronization (friends);
                clearFileWithUserRecipients ();
                friends.clear();
                loggedInUserId = 0;
                break;
            }
        }
    }
    return 0;
}

