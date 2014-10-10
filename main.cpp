#include <iostream>
#include <string.h>
#include "hash/Hash.hpp"

using namespace std;

int main(int argc, char** argv) {

    if (argc == 2) {
        cout << "Usage is -l DataFile -o OperationsFile -c config-file" << endl;
        exit(EXIT_SUCCESS);
    } else {

        string dataFile = "", operationsFile = "", configFile = "";

        cout << "Arguments given: ";
        for (int i = 1; i < argc; i++) {
            cout << argv[i] << " ";
            if (i + 1 != argc) {
                if ( !strcmp(argv[i], "-l") )
                    dataFile = argv[i+1];
                else if ( !strcmp(argv[i], "-o") )
                    operationsFile = argv[i+1];
                else if ( !strcmp(argv[i], "-c") )
                    configFile = argv[i+1];
            }
        }
        cout << endl;
        cout << "Datafile: " << dataFile << endl;

        Hash hash(10);
        InvertedIndexList invertedIndex;
        if (dataFile.compare(""))
            hash.loadDataFile(dataFile, &invertedIndex);

        invertedIndex.printPopulations();
        hash.printFirstNames();

        string line;
        while(cin) {
            getline(cin, line);
            if (!(line.compare("e")))
                break;
            else if (!(line.compare("min")))
                cout << hash.getMinPhoneNumber() << endl;
            else if (!(line.compare("max")))
                cout << hash.getMaxPhoneNumber() << endl;
            else if (line[0] == 'l' && line[1] == ' ') {
                string dataFile = line.substr(2);
                hash.loadDataFile(dataFile, &invertedIndex);
            }
        };

    }


    return 0;
}