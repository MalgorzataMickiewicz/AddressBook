#include "AddressBook.h"
#include "ManageUsers.h"
#include "AddresseeManager.h"

using namespace std;

int AddressBook::showMenu(int choice){
     system("cls");
        cout<<"1. Logowanie"<<endl;
        cout<<"2. Rejestracja"<<endl;
        cout<<"3. Zamknij program"<<endl;
        cout<<"Twoj wybor: ";
        cin>>choice;
        return choice;
}

int AddressBook::showSecondMenu(int choice){
     system("cls");
            cout<<"1. Dodaj adresata"<<endl;
            cout<<"2. Wyszukaj po imieniu"<<endl;
            cout<<"3. Wyszukaj po nazwisku"<<endl;
            cout<<"4. Wyswietl wszystkich adresatow"<<endl;
            cout<<"5. Usun adresata"<<endl;
            cout<<"6. Edytuj adresata"<<endl;
            cout<<"7. Zmien haslo"<<endl;
            cout<<"8. Wyloguj sie"<<endl;
            cout<<"Twoj wybor: ";
            cin>>choice;
            return choice;
}

void AddressBook::login(){
    manageUser.login();
    if(manageUser.ifUserIsLogg()){
        addresseeManager = new AddresseeManager(NAME_OF_FILE_WITH_ADDRESSEE, NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE, manageUser.giveIdLogedUser());
    }
}

void AddressBook::registerUser(){
    manageUser.registerUser();
}

void AddressBook::printAllUsers(){
    manageUser.printAllUsers();
}

void AddressBook::addAddressee(){
    addresseeManager->addAddressee();
}

void AddressBook::findAddresseeUsingName(){
    addresseeManager->findAddresseeUsingName();
}

void AddressBook::findAddresseeUsingLastName(){
    addresseeManager->findAddresseeUsingLastName();
}

void AddressBook::printAllAddressee(){
    addresseeManager->printAllAddressee();
}

void AddressBook::editAddressee(){
    addresseeManager->editAddressee();
}

void AddressBook::logoutUser(){
    manageUser.logoutUser();
    delete addresseeManager;
    addresseeManager = NULL;
}

bool AddressBook::ifUserIsLogg(){
    if(manageUser.ifUserIsLogg()){
    }
}

void AddressBook::changePassword(){
    manageUser.changePassword();
}
