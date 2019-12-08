#ifndef MANAGEFILE_H
#define MANAGEFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class ManageFiles: public TextFile{

    string nameOfTemporaryFileWithUsers = "UzytkownicyTymczasowi.txt";

    string changeDateOfUserToLineSeparatedWithVerticalLine(User user);
    User getDateOfUser(string dateOneUserSeparetedWithVerticalLines);

public:
    ManageFiles(string nameOfFile)
        : TextFile (nameOfFile) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void addUserWithNewPasswordToFile(User user, int idCurrentUser);
    int getIdOfUser(string dataOneUserSeparetedWithVerticalLines);
};

#endif
