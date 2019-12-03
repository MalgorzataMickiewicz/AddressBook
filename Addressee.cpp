#include "Addressee.h"

using namespace std;

//Setter
void Addressee::setAddresseeId(int newAddresseeId) {
    contactId=newAddresseeId;
}
void Addressee::setAddresseeName(string newAddresseeName) {
    name=newAddresseeName;
}
void Addressee::setAddresseeLastname(string newAddresseeLastname) {
    lastname=newAddresseeLastname;
}
void Addressee::setAddresseeMail(string newAddresseeMail) {
    mail=newAddresseeMail;
}
void Addressee::setAddresseeAddress(string newAddresseeAddress) {
    address=newAddresseeAddress;
}
void Addressee::setAddresseeTelelphoneNumber(string newAddresseeTelelphoneNumber) {
    telephoneNumber=newAddresseeTelelphoneNumber;
}
void Addressee::setIdLoggedUser(int newIdOfLoggedUser) {
    ID_LOGGED_USER=newIdOfLoggedUser;
}
//Getter
int Addressee::getAddresseeId() {
    return contactId;
}
string Addressee::getAddresseeName() {
    return name;
}
string Addressee::getAddresseeLastname() {
    return  lastname;
}
string Addressee::getAddresseeMail() {
    return   mail;
}
string Addressee::getAddresseeAddress() {
    return   address;
}
string Addressee::getAddresseeTelephoneNumber() {
    return  telephoneNumber;
}

int Addressee::getUserId() {
    return ID_LOGGED_USER;
}
