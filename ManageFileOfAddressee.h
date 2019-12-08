#ifndef MANAGEFILEOFADDRESSEE_H
#define MANAGEFILEOFADDRESSEE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "AuxiliaryMethods.h"
#include "Addressee.h"
#include "TextFile.h"

using namespace std;

class ManageFilesOfAddressee : public TextFile{

    string nameOfTemporaryFileWithAddressee = "AdresaciTymczasowi.txt";
    int idLastAddressee;
    int idCurrentAddressee;

    string changeDataOfAddresseeToLineSeparatedWithVerticalLine(Addressee addressee);
    Addressee getDataOfAddressee(string dataOneAddresseeSeparetedWithVerticalLines);
    string getNumber(string text, int characterPosition);
    int getIdAddresseeFromDataSeparateVerticalLine(string dataOneAddresseeSeparetedWithVerticalLines);

public:
    ManageFilesOfAddressee(string nameOfFile)
        : TextFile (nameOfFile) {
        idLastAddressee=0;
        };
    void addAddresseeToFile(Addressee addressee);
    void addChangeAddresseeToFile(Addressee addressee, int idCurrentAddressee);
    void addChangesToFile(int idDelatedAddressee);
    vector <Addressee> loadAddresseeFromFile(int idLogedUser);
    int getIdOfAddressee(string dataOneAddresseeSeparetedWithVerticalLines);
    int getIdOfUser(string dataOneAddresseeSeparetedWithVerticalLines);
    int getIdOfLastAddressee();
};

#endif

