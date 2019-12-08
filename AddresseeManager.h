#ifndef ADDRESSEEMANAGER_H
#define ADDRESSEEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "Addressee.h"
#include "ManageFileOfAddressee.h"
#include "AuxiliaryMethods.h"

using namespace std;

class AddresseeManager {

    const int ID_LOGGED_USER;
    vector <Addressee> addressees;
    Addressee addressee;
    ManageFilesOfAddressee manageFilesOfAddressee;

    Addressee giveDateOfNewAddressee();
    int getIdNewAddressee();

public:
    AddresseeManager(string nameOfFileWithAddressee, int idLoggedUser)
        : manageFilesOfAddressee(nameOfFileWithAddressee), ID_LOGGED_USER(idLoggedUser) {
    addressees = manageFilesOfAddressee.loadAddresseeFromFile(ID_LOGGED_USER);
    };
    void addAddressee();
    void printAllAddressee();
    void findAddresseeUsingName();
    void findAddresseeUsingLastName();
    void editAddressee();
    void delateAddressee();
    void changeConatctName(string newName, int choosenContactId, Addressee addressee);
    void changeConatctLastName(string newLastName, int choosenContactId, Addressee addressee);
    void changeConatctTelephone(string newTelephone, int choosenContactId, Addressee addressee);
    void changeConatctMail(string newEmail, int choosenContactId, Addressee addressee);
    void changeConatctAddress(string newAddress, int choosenContactId, Addressee addressee);
};

#endif
