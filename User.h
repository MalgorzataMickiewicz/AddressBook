#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User{

int id;
string password;
string nameOfUser;

public:

//Setter
    void setUserId(int newId);
    void setUserPassword(string newPassword);
    void setUserName(string newUserName);

//Getter
    int getUserId();
    string getUserPassword();
    string getUserName();
};

#endif
