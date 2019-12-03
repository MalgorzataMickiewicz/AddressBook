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
    AddresseeManager(string nameOfFileWithAddressee, string nameOfTemporaryFileWithAddressee,int idLoggedUser)
        : manageFilesOfAddressee(nameOfFileWithAddressee, nameOfTemporaryFileWithAddressee), ID_LOGGED_USER(idLoggedUser) {
    addressees = manageFilesOfAddressee.loadAddresseeFromFile();
    };
    void addAddressee();
    void printAllAddressee();
    void findAddresseeUsingName();
    void findAddresseeUsingLastName();
    void editAddressee();
    void changeConatctName(string newName, int choosenContactId, Addressee addressee);
    void changeConatctLastName(string newLastName, int choosenContactId);
    void changeConatctTelephone(string newTelephone, int choosenContactId);
    void changeConatctMail(string newEmail, int choosenContactId);
    void changeConatctAddress(string newAddress, int choosenContactId);
};

#endif
