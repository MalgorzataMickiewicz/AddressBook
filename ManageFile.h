#ifndef MANAGEFILE_H
#define MANAGEFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ManageFiles{

    const string nameOfFileWithUsers;
    //fstream textFile;

    bool isTheFileIsempty();
    string changeDateOfUserToLineSeparatedWithVerticalLine(User user);
    User getDateOfUser(string dateOneUserSeparetedWithVerticalLines);

public:
    ManageFiles(string NAME_OF_FILE_WITH_USERS)
        : nameOfFileWithUsers (NAME_OF_FILE_WITH_USERS) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void addUserWithNewPasswordToFile(User user, int idCurrentUser);
    int getIdOfUser(string dataOneUserSeparetedWithVerticalLines);
};

#endif

