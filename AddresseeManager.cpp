#include "AddresseeManager.h"
#include "User.h"

using namespace std;

void AddresseeManager::addAddressee() {
    Addressee addressee = giveDateOfNewAddressee();
    addressees.push_back(addressee);
    manageFilesOfAddressee.addAddresseeToFile(addressee);
    cout<<"Kontakt dodany"<<endl;
    Sleep(1000);
}

Addressee AddresseeManager::giveDateOfNewAddressee() {
    Addressee addressee;
    addressee.setAddresseeId(getIdNewAddressee());
    addressee.setIdLoggedUser(ID_LOGGED_USER);

    system("cls");
    string name;
    cout<<"Podaj imie kontaktu"<<endl;
    cin>>name;
    addressee.setAddresseeName(name);

    string lastname;
    cout<<"Podaj nazwisko kontaktu"<<endl;
    cin>>lastname;
    addressee.setAddresseeLastname(lastname);

    string telephoneNumber;
    cout<<"Podaj numer kontaktu"<<endl;
    cin>>telephoneNumber;
    addressee.setAddresseeTelelphoneNumber(telephoneNumber);

    string mail;
    cout<<"Podaj mail kontaktu"<<endl;
    cin>>mail;
    addressee.setAddresseeMail(mail);

    string address;
    cout<<"Podaj adres kontaktu"<<endl;
    cin.sync();
    getline(cin,address);
    addressee.setAddresseeAddress(address);

    return addressee;
}

int AddresseeManager::getIdNewAddressee() {
    if (addressees.empty() == true)
        return 1;
    else
        return addressees.back().getAddresseeId()+ 1;
}

void AddresseeManager::printAllAddressee() {
    int counter=0;
    for(int i=0; i<addressees.size(); i++) {
        cout<<addressees[i].getAddresseeId()<<endl;
        cout<<addressees[i].getUserId()<<endl;
        cout<<addressees[i].getAddresseeName()<<endl;
        cout<<addressees[i].getAddresseeLastname()<<endl;
        cout<<addressees[i].getAddresseeTelephoneNumber()<<endl;
        cout<<addressees[i].getAddresseeMail()<<endl;
        cout<<addressees[i].getAddresseeAddress()<<endl;
        system("Pause");
        counter++;
    }
    if(counter==0) {
        cout<<"Nie masz zadnych kontaktow w ksiazce adresowej"<<endl;
        system("Pause");
    }
}

void AddresseeManager::findAddresseeUsingName() {
    int counter=0;
    string name;
    cout<<"Podaj imie adresata aby wyszukac"<<endl;
    cin>>name;
    cout<<endl;

    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeName()==name) {
            cout<<addressees[i].getAddresseeId()<<endl;
            cout<<addressees[i].getUserId()<<endl;
            cout<<addressees[i].getAddresseeName()<<endl;
            cout<<addressees[i].getAddresseeLastname()<<endl;
            cout<<addressees[i].getAddresseeTelephoneNumber()<<endl;
            cout<<addressees[i].getAddresseeMail()<<endl;
            cout<<addressees[i].getAddresseeAddress()<<endl;
            system("Pause");
            counter++;
        }
    }
    if(counter==0) {
        cout<<"Nie masz kontaktu o takim imieniu"<<endl;
        system("Pause");
    }
}

void AddresseeManager::findAddresseeUsingLastName() {
    int counter=0;
    string lastname;
    cout<<"Podaj nazwisko adresata aby wyszukac"<<endl;
    cin>>lastname;
    cout<<endl;

    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeLastname()==lastname) {
            cout<<addressees[i].getAddresseeId()<<endl;
            cout<<addressees[i].getUserId()<<endl;
            cout<<addressees[i].getAddresseeName()<<endl;
            cout<<addressees[i].getAddresseeLastname()<<endl;
            cout<<addressees[i].getAddresseeTelephoneNumber()<<endl;
            cout<<addressees[i].getAddresseeMail()<<endl;
            cout<<addressees[i].getAddresseeAddress()<<endl;
            system("Pause");
            counter++;
        }
    }
    if(counter==0) {
        cout<<"Nie masz kontaktu o takim nazwisku"<<endl;
        system("Pause");
    }
}

void AddresseeManager::editAddressee() {
    Addressee addressee;
    int choosenContactId;
    int counter=0;
    char choice=0;

    system("cls");
    cout<<"Podaj numer ID kontaktu, ktory chcesz edytowac: ";
    cin>>choosenContactId;

    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            counter++;
            break;
        }
    }
    if(counter==1) {
        cout<<"Wybierz co chcesz edytowac:"<<endl;
        cout<<"1. Imie"<<endl;
        cout<<"2. Nazwisko"<<endl;
        cout<<"3. Numer telefonu"<<endl;
        cout<<"4. Email"<<endl;
        cout<<"5. Adres"<<endl;
        cout<<"6. Powrot do menu"<<endl;
        cout<<"Twoj wybor: ";
        cin>>choice;

    if(choice=='1') {
        string newName;
        cout<<"Podaj nowe imie: ";
        cin>>newName;
        changeConatctName(newName, choosenContactId, addressee);
    } else if(choice=='2') {
        string newLastName;
        cout<<"Podaj nowe nazwisko: ";
        cin>>newLastName;
        changeConatctLastName(newLastName, choosenContactId, addressee);
         addressee.setAddresseeName(newLastName);
    } else if(choice=='3') {
        string newTelephone;
        cout<<"Podaj nowy numer telefonu: ";
        cin>>newTelephone;
        changeConatctTelephone(newTelephone, choosenContactId, addressee);
    } else if(choice=='4') {
        string newEmail;
        cout<<"Podaj nowy adres mailowy: ";
        cin>>newEmail;
        changeConatctMail(newEmail, choosenContactId, addressee);
    } else if(choice=='5') {
        string newAddress;
        cout<<"Podaj nowy adres: ";
        cin>>newAddress;
        changeConatctAddress(newAddress, choosenContactId, addressee);
    } else if(choice=='6') {
    }
    }
    else{
        cout<<"Kontakt o podanym ID nie znajduje sie w Twojej ksiazce!"<<endl;
        system("Pause");
    }
}

void AddresseeManager::changeConatctName(string newName,int choosenContactId, Addressee addressee){
    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            addressees[i].setAddresseeName(newName);
            addressee.setAddresseeId(addressees[i].getAddresseeId());
            addressee.setIdLoggedUser(ID_LOGGED_USER);
            addressee.setAddresseeName(newName);
            addressee.setAddresseeLastname(addressees[i].getAddresseeLastname());
            addressee.setAddresseeTelelphoneNumber(addressees[i].getAddresseeTelephoneNumber());
            addressee.setAddresseeMail(addressees[i].getAddresseeMail());
            addressee.setAddresseeAddress(addressees[i].getAddresseeAddress());
            int idCurrentAddressee=addressees[i].getAddresseeId();
            manageFilesOfAddressee.addChangeAddresseeToFile(addressee, idCurrentAddressee);
            break;
        }
    }
}

void AddresseeManager::changeConatctLastName(string newLastName,int choosenContactId, Addressee addressee){
    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            addressees[i].setAddresseeLastname(newLastName);
            addressee.setAddresseeId(addressees[i].getAddresseeId());
            addressee.setIdLoggedUser(ID_LOGGED_USER);
            addressee.setAddresseeName(addressees[i].getAddresseeName());
            addressee.setAddresseeLastname(newLastName);
            addressee.setAddresseeTelelphoneNumber(addressees[i].getAddresseeTelephoneNumber());
            addressee.setAddresseeMail(addressees[i].getAddresseeMail());
            addressee.setAddresseeAddress(addressees[i].getAddresseeAddress());
            int idCurrentAddressee=addressees[i].getAddresseeId();
            manageFilesOfAddressee.addChangeAddresseeToFile(addressee, idCurrentAddressee);
            break;
        }
    }
}

void AddresseeManager::changeConatctTelephone(string newTelephone,int choosenContactId, Addressee addressee){
    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            addressees[i].setAddresseeTelelphoneNumber(newTelephone);
            addressee.setAddresseeId(addressees[i].getAddresseeId());
            addressee.setIdLoggedUser(ID_LOGGED_USER);
            addressee.setAddresseeName(addressees[i].getAddresseeName());
            addressee.setAddresseeLastname(addressees[i].getAddresseeLastname());
            addressee.setAddresseeTelelphoneNumber(newTelephone);
            addressee.setAddresseeMail(addressees[i].getAddresseeMail());
            addressee.setAddresseeAddress(addressees[i].getAddresseeAddress());
            int idCurrentAddressee=addressees[i].getAddresseeId();
            manageFilesOfAddressee.addChangeAddresseeToFile(addressee, idCurrentAddressee);
        }
            break;
    }
}

void AddresseeManager::changeConatctMail(string newMail,int choosenContactId, Addressee addressee){
    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            addressees[i].setAddresseeMail(newMail);
            addressee.setAddresseeId(addressees[i].getAddresseeId());
            addressee.setIdLoggedUser(ID_LOGGED_USER);
            addressee.setAddresseeName(addressees[i].getAddresseeName());
            addressee.setAddresseeLastname(addressees[i].getAddresseeLastname());
            addressee.setAddresseeTelelphoneNumber(addressees[i].getAddresseeTelephoneNumber());
            addressee.setAddresseeMail(newMail);
            addressee.setAddresseeAddress(addressees[i].getAddresseeAddress());
            int idCurrentAddressee=addressees[i].getAddresseeId();
            manageFilesOfAddressee.addChangeAddresseeToFile(addressee, idCurrentAddressee);
            break;
        }
    }
}

void AddresseeManager::changeConatctAddress(string newAddress,int choosenContactId, Addressee addressee){
    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            addressees[i].setAddresseeAddress(newAddress);
            addressee.setAddresseeId(addressees[i].getAddresseeId());
            addressee.setIdLoggedUser(ID_LOGGED_USER);
            addressee.setAddresseeName(addressees[i].getAddresseeName());
            addressee.setAddresseeLastname(addressees[i].getAddresseeLastname());
            addressee.setAddresseeTelelphoneNumber(addressees[i].getAddresseeTelephoneNumber());
            addressee.setAddresseeMail(addressees[i].getAddresseeMail());
            addressee.setAddresseeAddress(newAddress);
            int idCurrentAddressee=addressees[i].getAddresseeId();
            manageFilesOfAddressee.addChangeAddresseeToFile(addressee, idCurrentAddressee);
            break;
        }
    }
}

void AddresseeManager::delateAddressee(){
    Addressee addressee;
    int choosenContactId;
    int counter=0;
    char choice=0;
    int idDelatedAddressee=0;

    system("cls");
    cout<<"Podaj numer ID kontaktu, ktory chcesz usunac: ";
    cin>>choosenContactId;

    for(int i=0; i<addressees.size(); i++) {
        if(addressees[i].getAddresseeId()==choosenContactId) {
            idDelatedAddressee=addressees[i].getAddresseeId();
            counter++;
            break;
        }
    }

    if(counter==1) {
        cout<<"Jesli jestes pewien nacisnij 't' "<<endl;
        cin>>choice;

        if(choice=='t'){
            for(int j=0; j<addressees.size(); j++) {
                if(addressees[j].getAddresseeId()==choosenContactId) {
                    addressees.erase(addressees.begin()+j);
                }
            }
            manageFilesOfAddressee.addChangesToFile(idDelatedAddressee);
        }
        else{
            cout<<"Nie usunales zadnego kontakt"<<endl;
            system("Pause");
        }
}
 else{
        cout<<"Kontakt o podanym ID nie znajduje sie w Twojej ksiazce!"<<endl;
        system("Pause");
    }
}

