#include "User.h"

//Setter
void User::setUserId(int newId){
    id=newId;
}
void User::setUserPassword(string newPassword){
    password=newPassword;
}
void User::setUserName(string newUserName){
    nameOfUser=newUserName;
}

//Getter
    int User::getUserId() {
      return id;
	}
    string User::getUserPassword() {
      return password;
	}
	string User::getUserName() {
      return nameOfUser;
	}
