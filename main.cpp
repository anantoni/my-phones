#include <iostream>
#include <string.h>
#include "hash/Hash.hpp"
#include "record/myRecord.hpp"
#include "inverted_index/InvertedIndexList.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc == 2) {
        cout << "Usage is -l DataFile -o OperationsFile -c config-file" << endl;
        exit(EXIT_SUCCESS);
    } else {
        string dataFile, operationsFile, configFile;
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

        FILE *fpb = fopen(dataFile.c_str(), "rb");
        if (fpb == NULL) {
            cerr << "Cannot open binary file " << dataFile << endl;
            exit(EXIT_FAILURE);
        }

        // check number of records
        fseek(fpb, 0, SEEK_END);
        long lSize = ftell(fpb);
        rewind(fpb);

        MyRecord rec;
        int numOfrecords = (int) lSize/sizeof(rec);

        Hash hash(10);
        InvertedIndexList invertedIndexList;
        cout << "Records found in file " << numOfrecords << endl;
        for (int i = 0; i < numOfrecords; i++) {
            fread(&rec, sizeof(rec), 1, fpb);
            printf("%s %s %s %s %-5.2f\n", rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
            Record *record = new Record(rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
            if (hash.addRecord(record))
                invertedIndexList.addRecord(record);
        }
        fclose (fpb);

        invertedIndexList.printPopulations();
    }


    return 0;
}