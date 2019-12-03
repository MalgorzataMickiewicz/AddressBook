#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {

    AddressBook addressBook("Uzytkownicy.txt", "Adresaci.txt", "Adresaci_tymczasowi");
    int choice=0;

    while(1) {
        choice=addressBook.showMenu(choice);
        if(choice==1) {
            addressBook.login();
        } else if(choice==2) {
            addressBook.registerUser();
        } else if(choice==3) {
            exit(0);
        }

        while(addressBook.ifUserIsLogg()) {
            choice=addressBook.showSecondMenu(choice);
            if(choice==1) {
                addressBook.addAddressee();
            } else if(choice==2) {
                addressBook.findAddresseeUsingName();
            } else if(choice==3) {
                addressBook.findAddresseeUsingLastName();
            } else if(choice==4) {
                addressBook.printAllAddressee();
            } else if(choice==5) {
            } else if(choice==6) {
                addressBook.editAddressee();
            } else if(choice==7) {
                addressBook.changePassword();
            } else if(choice==8) {
                addressBook.logoutUser();
            }
        }
    }
    return 0;
}
