#ifndef MANAGEFILEOFADDRESSEE_H
#define MANAGEFILEOFADDRESSEE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "AuxiliaryMethods.h"
#include "Addressee.h"

using namespace std;

class ManageFilesOfAddressee{

    const string nameOfFileWithAddressee;
    const string nameOfTemporaryFileWithAddressee;
    fstream textFile;
    int idLastAddressee;

    bool isTheFileIsempty();
    string changeDataOfAddresseeToLineSeparatedWithVerticalLine(Addressee addressee);
    Addressee getDataOfAddressee(string dataOneAddresseeSeparetedWithVerticalLines);
    string getNumber(string text, int characterPosition);
    int getIdAddresseeFromDataSeparateVerticalLine(string dataOneAddresseeSeparetedWithVerticalLines);

public:
    ManageFilesOfAddressee(string NAME_OF_FILE_WITH_ADDRESSEE, string NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE)
        : nameOfFileWithAddressee (NAME_OF_FILE_WITH_ADDRESSEE, NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE) {
        idLastAddressee=0;
        };
    void addAddresseeToFile(Addressee addressee);
    void addChangeAddresseeToFile(Addressee addressee);
    vector <Addressee> loadAddresseeFromFile();
};

#endif

