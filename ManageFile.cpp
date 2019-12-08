#include <cstdlib>

#include "ManageFile.h"

using namespace std;

void ManageFiles::addUserToFile(User user){
    string lineWithDateOfUser = "";
    fstream textFile;
    textFile.open(getNameOfFile().c_str(), ios::app);

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
        cout << "Nie udalo sie otworzyc pliku " << getNameOfFile() << " i zapisac w nim danych." << endl;
}

 string ManageFiles::changeDateOfUserToLineSeparatedWithVerticalLine(User user){
 string lineWithDateOfUser = "";
    lineWithDateOfUser += AuxiliaryMethods::conversionIntToString(user.getUserId())+ '|';
    lineWithDateOfUser += user.getUserName() + '|';
    lineWithDateOfUser += user.getUserPassword() + '|';

    return lineWithDateOfUser;
}

vector <User> ManageFiles::loadUsersFromFile(){
    fstream textFile;
    User user;
    vector <User> users;
    string dataOneUserSeparetedWithVerticalLines = "";

    textFile.open(getNameOfFile().c_str(), ios::in);

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

void ManageFiles::addUserWithNewPasswordToFile(User user, int idCurrentUser){
    fstream textFile;
    string lineWithChangedDateOfUser = "";
    string dataOneUserSeparetedWithVerticalLines = "";
    int lineNumber=1;
    lineWithChangedDateOfUser = changeDateOfUserToLineSeparatedWithVerticalLine(user);

    textFile.open(getNameOfFile().c_str(), ios::in);
    if (textFile.good() == true) {

        while (getline(textFile, dataOneUserSeparetedWithVerticalLines)) {

            if(idCurrentUser==getIdOfUser(dataOneUserSeparetedWithVerticalLines)) {
                textFile.close();
                textFile.open("UzytkownicyTymczasowi.txt",ios::out | ios::app);
                textFile << lineWithChangedDateOfUser << endl;
                textFile.close();
                lineNumber++;
                textFile.open(getNameOfFile().c_str(), ios::in);
                for(int i=0; i<lineNumber-1; i++) {
                    getline(textFile, dataOneUserSeparetedWithVerticalLines);
                }
            } else {
                textFile.close();
                textFile.open("UzytkownicyTymczasowi.txt",ios::out | ios::app);
                textFile << dataOneUserSeparetedWithVerticalLines << endl;
                textFile.close();
                lineNumber++;
                textFile.open(getNameOfFile().c_str(), ios::in);
                for(int j=0; j<lineNumber-1; j++) {
                    getline(textFile, dataOneUserSeparetedWithVerticalLines);
                }
            }
        }
        textFile.close();
        remove("Uzytkownicy.txt");
        rename("UzytkownicyTymczasowi.txt", "Uzytkownicy.txt");
    } else
        cout << "Nie udalo sie otworzyc pliku " << getNameOfFile() << " i zapisac w nim danych." << endl;
}

int ManageFiles::getIdOfUser(string dataOneUserSeparetedWithVerticalLines) {
    string oneDataOfUser = "";
    int numberOfOneDataOfUser = 1;

    for (int characterPosition = 0; characterPosition < dataOneUserSeparetedWithVerticalLines.length(); characterPosition++) {
        if (dataOneUserSeparetedWithVerticalLines[characterPosition] != '|') {
            oneDataOfUser += dataOneUserSeparetedWithVerticalLines[characterPosition];
        } else {
            switch(numberOfOneDataOfUser) {
            case 1:
                int userId=atoi(oneDataOfUser.c_str());
                return userId;
            }
        }
    }
}
