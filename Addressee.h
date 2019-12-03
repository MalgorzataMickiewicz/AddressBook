#ifndef ADDRESSEE_H
#define ADDRESSEE_H

#include <string>

using namespace std;

class Addressee {

    int contactId;
    int ID_LOGGED_USER;
    string name;
    string lastname;
    string mail;
    string address;
    string telephoneNumber;

public:

//Setter
    void setAddresseeId(int newAddresseeId);
    void setAddresseeName(string newAddresseeName);
    void setAddresseeLastname(string newAddresseeLastname);
    void setAddresseeMail(string newAddresseeMail);
    void setAddresseeAddress(string newAddresseeAddress);
    void setAddresseeTelelphoneNumber(string newAddresseeTelelphoneNumber);
    void setIdLoggedUser(int newIdOfLoggedUser);

//Getter
    int getAddresseeId();
    string getAddresseeName();
    string getAddresseeLastname();
    string getAddresseeMail();
    string getAddresseeAddress();
    string getAddresseeTelephoneNumber();
    int getUserId();

};

#endif
