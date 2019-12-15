#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "ManageUsers.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook{
    ManageUsers manageUser; //tworzymy obiekt klasy ManageUser. W klasie ManageUser mamy metody, z ktorych chcemy skorzystac
    AddresseeManager *addresseeManager;
    const string NAME_OF_FILE_WITH_ADDRESSEE;

public:
    AddressBook(string nameOfFileWithUsers, string nameOfFileWithAddressee)
        : manageUser(nameOfFileWithUsers), NAME_OF_FILE_WITH_ADDRESSEE(nameOfFileWithAddressee)
    {addresseeManager = NULL;
    };
    ~AddressBook(){
    delete addresseeManager;
    addresseeManager = NULL;
    }
    int showMenu(int choice);
    int showSecondMenu(int choice);
    void login();
    void registerUser();
    void printAllUsers();
    void logoutUser();
    void addAddressee();
    void printAllAddressee();
    void findAddresseeUsingName();
    void findAddresseeUsingLastName();
    bool ifUserIsLogg();
    void editAddressee();
    void changePassword();
    void delateAddressee();
};

#endif
