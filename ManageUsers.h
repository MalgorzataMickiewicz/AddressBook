#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "User.h"
#include "AddresseeManager.h"
#include "ManageFile.h"

using namespace std;

class ManageUsers {

    vector <User> users;
    int idLogedUser;
    ManageFiles manageFiles;

    User giveDateOfNewUser();
    bool checkExistingOfName(string nameOfUser);
    bool checkUserPassword(string nameOfUser);

public:
    ManageUsers(string nameOfFileWithUsers) : manageFiles(nameOfFileWithUsers) {
        idLogedUser = 0;
        users = manageFiles.loadUsersFromFile();
    };
    void registerUser();
    void printAllUsers();
    void login();
    bool ifUserIsLogg();
    int getIdNewUser();
    void logoutUser();
    int giveIdLogedUser();
    void changePassword();
    void addNewPasswordToVector(string password);
};

#endif

