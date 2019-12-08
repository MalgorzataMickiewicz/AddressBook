#include "ManageUsers.h"

using namespace std;

void ManageUsers::registerUser() {
    User user = giveDateOfNewUser();
    users.push_back(user);
    manageFiles.addUserToFile(user);
    cout<<"Konto zalozone"<<endl;
    Sleep(1000);
}

User ManageUsers::giveDateOfNewUser() {
    User user;
    user.setUserId(getIdNewUser());

    string nameOfUser;
    do {
        cout << "----------"<<endl << "Podaj login: ";
        cin>>nameOfUser;
        user.setUserName(nameOfUser);

    } while (checkExistingOfName(user.getUserName()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin>>password;
    user.setUserPassword(password);

    return user;
}

int ManageUsers::getIdNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId()+ 1;
}

bool ManageUsers::checkExistingOfName(string nameOfUser) {
    for(int i=0; i<users.size(); i++) {
        if(users[i].getUserName()==nameOfUser) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void ManageUsers::printAllUsers() {
    for(int i=0; i<users.size(); i++) {
        cout<<users[i].getUserId()<<endl;
        cout<<users[i].getUserName()<<endl;
        cout<<users[i].getUserPassword()<<endl;
        system("Pause");
    }
}

void ManageUsers::login() {
    User user;
    int counter=0;
    string nameOfUser;
    string password;
    cout << "----------"<<endl<<"Podaj login: ";
    cin>>nameOfUser;

    for(int i=0; i<users.size(); i++) {
        if(users[i].getUserName()== nameOfUser) {
            for(int j=0; j<3; j++) {
                cout<<"Podaj haslo. Pozostalo prob: "<<3-j<<": ";
                cin>>password;
                if(users[i].getUserPassword()==password) {
                    idLogedUser=users[i].getUserId();
                    cout<<"Zalogowales sie"<<endl;
                    Sleep(1000);
                    j=3;
                    counter++;
                }
                else if(j==2){
                    cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy i sprobuj ponownie"<<endl;
                    Sleep(3000);
                    j=-1;
                    system("cls");
                }
        }
        }
        }
        if(counter==0){
        cout<<"Nie ma uzytkownika z takim loginem"<<endl;
        Sleep(1000);
    }
}

bool ManageUsers::ifUserIsLogg(){
    if(idLogedUser > 0){
        return true;
    }
    else{
        return false;
    }
}

int ManageUsers::giveIdLogedUser(){
    return idLogedUser;
}

void ManageUsers::logoutUser(){
    idLogedUser = 0;
}

void ManageUsers::changePassword(){
    string password;
    cout<<"Podaj nowe haslo: ";
    cin>>password;
    addNewPasswordToVector(password);
}

void ManageUsers::addNewPasswordToVector(string password){
    User user;
    for(int i=0; i<users.size(); i++) {
        if(users[i].getUserId()==idLogedUser) {
            users[i].setUserPassword(password);
            user.setUserPassword(password);
            user.setUserId(idLogedUser);
            user.setUserName(users[i].getUserName());
            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1000);
            int idCurrentUser=users[i].getUserId();
            manageFiles.addUserWithNewPasswordToFile(user, idCurrentUser);
        }
    }
}
