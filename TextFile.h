
#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile{
    const string NAME_OF_FILE;

public:
    TextFile(string nameOfFile) : NAME_OF_FILE(nameOfFile){
    }
    string getNameOfFile(){
    return NAME_OF_FILE;}

    bool isTheFileIsempty();
    bool isTheTemporaryFileIsempty();
};

#endif

