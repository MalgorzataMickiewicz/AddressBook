#include <cstdlib>

#include "ManageFileOfAddressee.h"

using namespace std;

void ManageFilesOfAddressee::addAddresseeToFile(Addressee addressee) {
    fstream textFile;
    string lineWithDataOfAddressee = "";
    textFile.open(getNameOfFile().c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithDataOfAddressee = changeDataOfAddresseeToLineSeparatedWithVerticalLine(addressee);

        if (isTheFileIsempty() == true) {
            textFile << lineWithDataOfAddressee;
        } else {
            textFile << endl << lineWithDataOfAddressee ;
        }
        textFile.close();
        idLastAddressee++;
    } else
        cout << "Nie udalo sie otworzyc pliku " << getNameOfFile() << " i zapisac w nim danych." << endl;
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

vector <Addressee> ManageFilesOfAddressee::loadAddresseeFromFile(int idLogedUser) {
    fstream textFile;
    Addressee addressee;
    vector <Addressee> addressees;
    string dataOneAddresseeSeparetedWithVerticalLines = "";
    string dataOfLastAddressee = "";

    textFile.open(getNameOfFile().c_str(), ios::in);
    if (textFile.good() == true) {
        while (getline(textFile, dataOneAddresseeSeparetedWithVerticalLines)) {
            addressee = getDataOfAddressee(dataOneAddresseeSeparetedWithVerticalLines);
            if(idLogedUser==getIdOfUser(dataOneAddresseeSeparetedWithVerticalLines)) {
                addressees.push_back(addressee);
            }
            dataOfLastAddressee = dataOneAddresseeSeparetedWithVerticalLines;
        }
        textFile.close();
    }
    if(dataOfLastAddressee!= "") {
        idLastAddressee = getIdOfAddressee(dataOfLastAddressee);
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

int ManageFilesOfAddressee::getIdOfUser(string dataOneAddresseeSeparetedWithVerticalLines) {
    fstream textFile;
    string oneDataOfAddressee = "";
    int numberOfOneDataOfAddressee = 1;
    int userId = 0;

    for (int characterPosition = 0; characterPosition < dataOneAddresseeSeparetedWithVerticalLines.length(); characterPosition++) {
        if (dataOneAddresseeSeparetedWithVerticalLines[characterPosition] != '|') {
            oneDataOfAddressee += dataOneAddresseeSeparetedWithVerticalLines[characterPosition];
        } else {
            switch(numberOfOneDataOfAddressee) {
            case 1:
                numberOfOneDataOfAddressee++;
                oneDataOfAddressee= "";
                break;
            case 2:
                userId=atoi(oneDataOfAddressee.c_str());
                return userId;
            }
        }
    }
}

void ManageFilesOfAddressee::addChangeAddresseeToFile(Addressee addressee, int idCurrentAddressee) {
    fstream textFile;
    string lineWithChangedDataOfAddressee = "";
    string dataOneAddresseeSeparetedWithVerticalLines = "";
    int lineNumber=1;

    lineWithChangedDataOfAddressee = changeDataOfAddresseeToLineSeparatedWithVerticalLine(addressee);

    textFile.open(getNameOfFile().c_str(), ios::in);
    if (textFile.good() == true) {

        while (getline(textFile, dataOneAddresseeSeparetedWithVerticalLines)) {

            if(idCurrentAddressee==getIdOfAddressee(dataOneAddresseeSeparetedWithVerticalLines)) {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                if (isTheFileIsempty() == true) {
                    textFile << dataOneAddresseeSeparetedWithVerticalLines;
                } else {
                    textFile << endl << dataOneAddresseeSeparetedWithVerticalLines ;
                }
                textFile.close();
                lineNumber++;
                textFile.open(getNameOfFile().c_str(), ios::in);
                for(int i=0; i<lineNumber-1; i++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            } else {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                if (isTheTemporaryFileIsempty() == true) {
                    textFile << dataOneAddresseeSeparetedWithVerticalLines;
                } else {
                    textFile << endl << dataOneAddresseeSeparetedWithVerticalLines ;
                }
                textFile.close();
                lineNumber++;
                textFile.open(getNameOfFile().c_str(), ios::in);
                for(int j=0; j<lineNumber-1; j++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            }
        }
        textFile.close();
        remove("Adresaci.txt");
        rename("AdresaciTymczasowi.txt", "Adresaci.txt");
    } else
        cout << "Nie udalo sie otworzyc pliku " << getNameOfFile() << " i zapisac w nim danych." << endl;
}

int ManageFilesOfAddressee::getIdOfAddressee(string dataOneAddresseeSeparetedWithVerticalLines) {
    string oneDataOfAddressee = "";
    int numberOfOneDataOfAddressee = 1;

    for (int characterPosition = 0; characterPosition < dataOneAddresseeSeparetedWithVerticalLines.length(); characterPosition++) {
        if (dataOneAddresseeSeparetedWithVerticalLines[characterPosition] != '|') {
            oneDataOfAddressee += dataOneAddresseeSeparetedWithVerticalLines[characterPosition];
        } else {
            switch(numberOfOneDataOfAddressee) {
            case 1:
                int contactId=atoi(oneDataOfAddressee.c_str());
                return contactId;
            }
        }
    }
}

void ManageFilesOfAddressee::addChangesToFile(int idDelatedAddressee) {
    string dataOfLastAddressee = "";
    fstream textFile;
    string lineWithChangedDataOfAddressee = "";
    string dataOneAddresseeSeparetedWithVerticalLines = "";
    int lineNumber=1;

    textFile.open(getNameOfFile().c_str(), ios::in);
    if (textFile.good() == true) {

        while (getline(textFile, dataOneAddresseeSeparetedWithVerticalLines)) {

            if(idDelatedAddressee==getIdOfAddressee(dataOneAddresseeSeparetedWithVerticalLines)) {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);
                textFile.close();
                lineNumber++;
                textFile.open(getNameOfFile().c_str(), ios::in);
                for(int i=0; i<lineNumber-1; i++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            } else {
                textFile.close();
                textFile.open("AdresaciTymczasowi.txt",ios::out | ios::app);

                if (isTheTemporaryFileIsempty() == true) {
                    textFile << dataOneAddresseeSeparetedWithVerticalLines;
                } else {
                    textFile << endl << dataOneAddresseeSeparetedWithVerticalLines ;
                }
                dataOfLastAddressee = dataOneAddresseeSeparetedWithVerticalLines;
                textFile.close();
                lineNumber++;
                textFile.open(getNameOfFile().c_str(), ios::in);
                for(int j=0; j<lineNumber-1; j++) {
                    getline(textFile, dataOneAddresseeSeparetedWithVerticalLines);
                }
            }
        }
        idLastAddressee=getIdOfAddressee(dataOfLastAddressee);
        textFile.close();
        remove("Adresaci.txt");
        rename("AdresaciTymczasowi.txt", "Adresaci.txt");
    } else
        cout << "Nie udalo sie otworzyc pliku " << getNameOfFile() << " i zapisac w nim danych." << endl;
}

int ManageFilesOfAddressee::getIdOfLastAddressee() {
    return idLastAddressee;
}
