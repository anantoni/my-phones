#include <iostream>
#include <string.h>
#include <bits/stl_algo.h>
#include <complex>
#include <fstream>
#include "Hash.hpp"
#include "InvertedIndexList.hpp"

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
        cout << "Operations file: " << operationsFile << endl;
        cout << "Configuration file: " << configFile << endl << endl;
        InvertedIndexList invertedIndex;
        Hash hash(10, &invertedIndex);

        if (dataFile.compare("")) {
            hash.loadDataFile(dataFile);
            cout << endl;
        }

        if (operationsFile.compare("")) {
            ifstream ifs;
            ifs.open(operationsFile);
            if (!ifs.is_open())
                cerr << "Operations file " << dataFile <<  " not found" << endl;
            else {
                hash.readFromStream(ifs);
                cout << endl;
            }
        }

        hash.readFromStream(cin);

    }
    return 0;
}