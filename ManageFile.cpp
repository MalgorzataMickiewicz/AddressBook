#include <cstdlib>

#include "ManageFile.h"

using namespace std;

void ManageFiles::addUserToFile(User user){

    string lineWithDateOfUser = "";
    textFile.open(nameOfFileWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithDateOfUser = changeDateOfUserToLineSeparatedWithVerticalLine(user);

        if (isTheFileIsempty() == true)
        {
            textFile << lineWithDateOfUser;
        }
        else
        {
            textFile << endl << lineWithDateOfUser ;
        }

        textFile.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nameOfFileWithUsers << " i zapisac w nim danych." << endl;
}

bool ManageFiles::isTheFileIsempty(){

    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

 string ManageFiles::changeDateOfUserToLineSeparatedWithVerticalLine(User user){
 string lineWithDateOfUser = "";

    lineWithDateOfUser += AuxiliaryMethods::conversionIntToString(user.getUserId())+ '|';
    lineWithDateOfUser += user.getUserName() + '|';
    lineWithDateOfUser += user.getUserPassword() + '|';

    return lineWithDateOfUser;
}

vector <User> ManageFiles::loadUsersFromFile(){

    User user;
    vector <User> users;
    string dataOneUserSeparetedWithVerticalLines = "";

    textFile.open(nameOfFileWithUsers.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, dataOneUserSeparetedWithVerticalLines))
        {
            user = getDateOfUser(dataOneUserSeparetedWithVerticalLines);
            users.push_back(user);
        }
        textFile.close();
    }
  return users;
}

User ManageFiles::getDateOfUser(string dataOneUserSeparetedWithVerticalLines){
    User user;
    string oneDateOfUser = "";
    int numberOfOneDateOfUser = 1;

    for (int characterPosition = 0; characterPosition < dataOneUserSeparetedWithVerticalLines.length(); characterPosition++)
    {
        if (dataOneUserSeparetedWithVerticalLines[characterPosition] != '|')
        {
            oneDateOfUser += dataOneUserSeparetedWithVerticalLines[characterPosition];
        }
        else
        {
            switch(numberOfOneDateOfUser)
            {
            case 1:
                user.setUserId(atoi(oneDateOfUser.c_str()));
                break;
            case 2:
                user.setUserName(oneDateOfUser);
                break;
            case 3:
                user.setUserPassword(oneDateOfUser);
                break;
            }
            oneDateOfUser = "";
            numberOfOneDateOfUser++;
        }
    }
    return user;
}

void ManageFiles::addUserWithNewPasswordToFile(User user){
    string lineWithDateOfUser = "";
    textFile.open(nameOfFileWithUsers.c_str(),ios::out | ios::app);


}
