#include "TextFile.h"

using namespace std;

bool TextFile::isTheFileIsempty(){
    bool empty = true;
    fstream textFile;
    textFile.open(getNameOfFile().c_str(), ios::app);

        if (textFile.good() == true)
        {
            textFile.seekg(0, ios::end);
            if (textFile.tellg() != 0)
                empty = false;
        }

        textFile.close();
        return empty;
    }

