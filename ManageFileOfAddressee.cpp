#include <cstdlib>

#include "ManageFileOfAddressee.h"

using namespace std;

void ManageFilesOfAddressee::addAddresseeToFile(Addressee addressee) {

    string lineWithDataOfAddressee = "";
    textFile.open(nameOfFileWithAddressee.c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithDataOfAddressee = changeDataOfAddresseeToLineSeparatedWithVerticalLine(addressee);

        if (isTheFileIsempty() == true) {
            textFile << lineWithDataOfAddressee;
        } else {
            textFile << lineWithDataOfAddressee << endl ;
        }
        textFile.close();
    } else
        cout << "Nie udalo sie otworzyc pliku " << nameOfFileWithAddressee << " i zapisac w nim danych." << endl;
}

string ManageFilesOfAddressee::changeDataOfAddresseeToLineSeparatedWithVerticalLine(Addressee addressee) {
    string lineWithDataOfAddressee = "";

    lineWithDataOfAddressee += AuxiliaryMethods::conversionIntToString(addressee.getAddresseeId())+ '|';
    lineWithDataOfAddressee += AuxiliaryMethods::conversionIntToString(addressee.getUserId()) + '|';
    lineWithDataOfAddressee += addressee.getAddresseeName() + '|';
    lineWithDataOfAddressee += addressee.getAddresseeLastname() + '|';
    lineWithDataOfAddressee += addressee.getAddresseeTelephoneNumber() + '|';
    lineWithDataOfAddressee += addressee.getAddresseeMail() + '|';
    lineWithDataOfAddressee += addressee.getAddresseeAddress() + '|';

    return lineWithDataOfAddressee;
}

vector <Addressee> ManageFilesOfAddressee:: loadAddresseeFromFile() {

    Addressee addressee;
    vector <Addressee> addressees;
    string dataOneAddresseeSeparetedWithVerticalLines = "";

    textFile.open(nameOfFileWithAddressee.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, dataOneAddresseeSeparetedWithVerticalLines)) {
            addressee = getDataOfAddressee(dataOneAddresseeSeparetedWithVerticalLines);
            addressees.push_back(addressee);
        }
        textFile.close();
    }
    return addressees;
}

Addressee ManageFilesOfAddressee::getDataOfAddressee(string dataOneAddresseeSeparetedWithVerticalLines) {
    Addressee addressee;
    string oneDataOfAddressee = "";
    int numberOfOneDataOfAddressee = 1;

    for (int characterPosition = 0; characterPosition < dataOneAddresseeSeparetedWithVerticalLines.length(); characterPosition++) {
        if (dataOneAddresseeSeparetedWithVerticalLines[characterPosition] != '|') {
            oneDataOfAddressee += dataOneAddresseeSeparetedWithVerticalLines[characterPosition];
        } else {
            switch(numberOfOneDataOfAddressee) {
            case 1:
                addressee.setAddresseeId(atoi(oneDataOfAddressee.c_str()));
                break;
            case 2:
                addressee.setIdLoggedUser(atoi(oneDataOfAddressee.c_str()));
                break;
            case 3:
                addressee.setAddresseeName(oneDataOfAddressee);
                break;
            case 4:
                addressee.setAddresseeLastname(oneDataOfAddressee);
                break;
            case 5:
                addressee.setAddresseeTelelphoneNumber(oneDataOfAddressee);
                break;
            case 6:
                addressee.setAddresseeMail(oneDataOfAddressee);
                break;
            case 7:
                addressee.setAddresseeAddress(oneDataOfAddressee);
                break;
            }
            oneDataOfAddressee= "";
            numberOfOneDataOfAddressee++;
        }
    }
    return addressee;
}

bool ManageFilesOfAddressee::isTheFileIsempty() {

    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

void ManageFilesOfAddressee::addChangeAddresseeToFile(Addressee addressee, int idCurrentAddressee) {

    string lineWithChangedDataOfAddressee = "";
    string dataOneAddresseeSeparetedWithVerticalLines = "";
    int contactId;
    int lineNumber=1;

    lineWithChangedDataOfAddressee = changeDataOfAddresseeToLineSeparatedWithVerticalLine(addressee);

    textFile.open(nameOfFileWithAddressee.c_str(), ios::in);
    if (textFile.good() == true) {

        while (getline(textFile, dataOneAddresseeSeparetedWithVerticalLines)) {
            contactId = getIdOfAddressee(dataOneAddresseeSeparetedWithVerticalLines);

            if(idCurrentAddressee==contactId) {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                textFile << lineWithChangedDataOfAddressee << endl;
                textFile.close();
                lineNumber++;
                textFile.open(nameOfFileWithAddressee.c_str(), ios::in);
                for(int i=0; i<lineNumber-1; i++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            } else {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                textFile << dataOneAddresseeSeparetedWithVerticalLines << endl;
                textFile.close();
                lineNumber++;
                textFile.open(nameOfFileWithAddressee.c_str(), ios::in);
                for(int j=0; j<lineNumber-1; j++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            }
        }
        textFile.close();
        remove("Adresaci.txt");
        rename("AdresaciTymczasowi.txt", "Adresaci.txt");
    } else
        cout << "Nie udalo sie otworzyc pliku " << nameOfFileWithAddressee << " i zapisac w nim danych." << endl;
}

int ManageFilesOfAddressee::getIdOfAddressee(string dataOneAddresseeSeparetedWithVerticalLines) {

    string oneDataOfAddressee = "";
    int numberOfOneDataOfAddressee = 1;
    int contactId=0;

    for (int characterPosition = 0; characterPosition < dataOneAddresseeSeparetedWithVerticalLines.length(); characterPosition++) {
        if (dataOneAddresseeSeparetedWithVerticalLines[characterPosition] != '|') {
            oneDataOfAddressee += dataOneAddresseeSeparetedWithVerticalLines[characterPosition];
        } else {
            switch(numberOfOneDataOfAddressee) {
            case 1:
                contactId=atoi(oneDataOfAddressee.c_str());
                return contactId;
            }
        }
    }
}

void ManageFilesOfAddressee::addChangesToFile(int idDelatedAddressee){
    string lineWithChangedDataOfAddressee = "";
    string dataOneAddresseeSeparetedWithVerticalLines = "";
    int contactId;
    int lineNumber=1;

    textFile.open(nameOfFileWithAddressee.c_str(), ios::in);
    if (textFile.good() == true) {

        while (getline(textFile, dataOneAddresseeSeparetedWithVerticalLines)) {
            contactId = getIdOfAddressee(dataOneAddresseeSeparetedWithVerticalLines);

            if(idDelatedAddressee==contactId) {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                textFile.close();
                lineNumber++;
                textFile.open(nameOfFileWithAddressee.c_str(), ios::in);
                for(int i=0; i<lineNumber-1; i++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            } else {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                textFile << dataOneAddresseeSeparetedWithVerticalLines << endl;
                textFile.close();
                lineNumber++;
                textFile.open(nameOfFileWithAddressee.c_str(), ios::in);
                for(int j=0; j<lineNumber-1; j++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            }
        }
        textFile.close();
        remove("Adresaci.txt");
        rename("AdresaciTymczasowi.txt", "Adresaci.txt");
    } else
        cout << "Nie udalo sie otworzyc pliku " << nameOfFileWithAddressee << " i zapisac w nim danych." << endl;
}

