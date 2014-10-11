#include <iostream>
#include <string.h>
#include <bits/stl_algo.h>
#include <complex>
#include "hash/Hash.hpp"

using namespace std;

string* splitCommand(string line) {
    string *recordArgs = new string[5];
    string delimiter = " ";

    size_t pos = 0;
    int i = 0;
    string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        if (i > 3)
            return nullptr;

        token = line.substr(0, pos);
        recordArgs[i] = token;
        cout << token << endl;
        line.erase(0, pos + delimiter.length());
        i++;
    }
    recordArgs[4] = line;
    return recordArgs;
}


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

        InvertedIndexList invertedIndex;
        Hash hash(10, &invertedIndex);

        if (dataFile.compare(""))
            hash.loadDataFile(dataFile);

        hash.printFirstNames();

        string line;
        while(cin) {
            getline(cin, line);
            if (line[0] == 'i' && line[1] == ' ') {
                string* recordArgs = splitCommand(line.substr(2));
                if (recordArgs == nullptr) {
                    cout << "Invalid insert command" << endl;
                    continue;
                }
                Record *record = new Record(recordArgs[0], recordArgs[2], recordArgs[1],
                        recordArgs[3], atof(recordArgs[4].c_str()));
                hash.addRecord(record);
                hash.sortInvertedIndex();
            }
            else if (line[0] == 'd' && line[1] == ' ') {
                string phone = line.substr(2);
                hash.deleteRecord(phone);
                hash.sortInvertedIndex();
            }
            else if (line[0] == 'q' && line[1] == ' ') {
                string phone = line.substr(2);
                hash.queryRecord(phone);
            }
            else if (line[0] == 's' && line[1] == ' ') {
                string town = line.substr(2);
                invertedIndex.printInvoiceSum(town);
            }
            else if (!(line.compare("e")))
                break;
            else if (!(line.compare("min")))
                cout << hash.getMinPhoneNumber() << endl;
            else if (!(line.compare("max")))
                cout << hash.getMaxPhoneNumber() << endl;
            else if (line[0] == 'l' && line[1] == ' ') {
                string dataFile = line.substr(2);
                hash.loadDataFile(dataFile);
            }
            else if (line[0] == 'f' && line[1] == 't' && line[2] == ' ') {
                string town;
                string l;
                std::size_t found = line.find(' ', 3);
                if (found != std::string::npos) {
                    cout << "found: " << found << endl;
                    town = line.substr(3, found - 3);
                    l = line.substr(found + 1);
                }
                else {
                    cout << "Usage: ft town l where l is a number" << endl;
                    continue;
                }

                cout << town << endl;
                cout << l << endl;
                if (l.find_first_not_of("0123456789") != std::string::npos) {
                    cout << "Usage: \"ft town l\" where l is a number" << endl;
                    continue;
                }

                invertedIndex.printTownTopSpenders(town, atoi(l.c_str()));
            }
            else if (line[0] == 't' && line[1] == ' ') {
                string k = line.substr(2);
                if (k.find_first_not_of("0123456789") != std::string::npos) {
                    cout << "Usage: \"t k\" where  is a number" << endl;
                    continue;
                }
                invertedIndex.printTopTowns(atoi(k.c_str()));
            }
            else if (line[0] == 'p' && line[1] == ' ') {
                string town = line.substr(2);
                invertedIndex.printPopulation(town);
            }
        }
    }

    return 0;
}