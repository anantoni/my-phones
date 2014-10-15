#include <sstream>
#include <fstream>
#include "Hash.hpp"
#include "../record/myRecord.hpp"

Hash::Hash(int bucketNumber, InvertedIndexList *invertedIndex) {
    this->bucketNumber = bucketNumber;
    if ((bucketList = new Bucket*[bucketNumber]) == nullptr) {
        cerr << "Error in bucket list allocation" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < bucketNumber; i++)
        bucketList[i] = new Bucket();

    this->invertedIndex = invertedIndex;
    this->min = 0;
    this->max = 0;
}

Hash::~Hash() {
    for (int i = 0; i < bucketNumber; i++)
        delete bucketList[i];
    cout << "Hash Destroyed" << endl;
}

int Hash::selectBucket(string phone) {
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(phone);

    return str_hash%bucketNumber;
}

bool Hash::addRecord(Record *record) {
    int bucketSelection = selectBucket(record->getPhone());

    if (bucketList[bucketSelection]->pushBack(record) == true) {
        cout << "Phone number " << record->getPhone() << " added successfully" << endl;
        invertedIndex->addRecord(record);

        long phone = atol(record->getPhone().c_str());
        if (phone > max)
            max = phone;
        if (phone < min || min == 0)
            min = phone;
        return true;
    }
    else {
        cout << "Record not added: Duplicate phone number exists." << endl;
        return false;
    }
}

bool Hash::deleteRecord(string phone) {
    int bucketSelection = selectBucket(phone);
    string town = bucketList[bucketSelection]->deleteRecord(phone);
    if (town.compare("")) {
        cout << "Phone number " << phone << " deleted successfully." << endl;
        invertedIndex->deleteRecord(town, phone);

        long deletedPhone = atol(phone.c_str());

        if (deletedPhone == min) {
            min = 0;
            updateMin();
        }
        if (deletedPhone == max) {
            max = 0;
            updateMax();
        }
    }
    else
        cout << "Phone number not found." << endl;
}

void Hash::queryRecord(string phone) {
    int bucketSelection = selectBucket(phone);
    bucketList[bucketSelection]->queryRecord(phone);
}

void Hash::printFirstNames() {
    for (int i = 0; i < bucketNumber; i++)
        bucketList[i]->printAllFirstNames();
}

void Hash::loadDataFile(string dataFile) {
    FILE *fpb = fopen(dataFile.c_str(), "rb");
    if (fpb == NULL) {
        cout << "Data file " << dataFile << " not found" << endl;
        return;
    }

    // check number of records
    fseek(fpb, 0, SEEK_END);
    long lSize = ftell(fpb);
    rewind(fpb);

    MyRecord rec;
    size_t numOfrecords = (int) lSize/sizeof(rec);

    //cout << "Records found in file " << numOfrecords << endl;
    for (int i = 0; i < numOfrecords; i++) {
        fread(&rec, sizeof(rec), 1, fpb);
//        printf("%s %s %s %s %-5.2f\n", rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
        Record *record = new Record(rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
        this->addRecord(record);
    }
    fclose (fpb);
    invertedIndex->sort();
//    invertedIndex->printPopulations();
    cout << "Data file loaded successfully" << endl;
}

long Hash::getMaxPhoneNumber() {
    return this->max;
}

long Hash::getMinPhoneNumber() {
    return this->min;
}

void Hash::updateMin() {
    for (int i = 0; i < bucketNumber; i++) {
        long bucketMin = bucketList[i]->getBucketMin();
        if (bucketMin != -1 && (bucketMin < min || min == 0))
            min = bucketMin;
    }
}

void Hash::updateMax() {
    for (int i = 0; i < bucketNumber; i++) {
        long bucketMax = bucketList[i]->getBucketMax();
        if (bucketMax != -1 && bucketMax > max)
            max = bucketMax;
    }
}

void Hash::sortInvertedIndex() {
    this->invertedIndex->sort();
}

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
        line.erase(0, pos + delimiter.length());
        i++;
    }
    recordArgs[4] = line;
    return recordArgs;
}


void Hash::readFromStream(istream &is) {
    string line;
    while(is) {
        getline(is, line);
        if (is != cin)
            cout << "myphones> " << line << endl;
        if (line[0] == 'i' && line[1] == ' ') {
            string *recordArgs = splitCommand(line.substr(2));
            if (recordArgs == nullptr) {
                cout << "Invalid insert command" << endl;
                continue;
            }
            Record *record = new Record(recordArgs[0], recordArgs[1], recordArgs[2],
                    recordArgs[3], atof(recordArgs[4].c_str()));
            addRecord(record);
            sortInvertedIndex();
        }
        else if (line[0] == 'd' && line[1] == ' ') {
            string phone = line.substr(2);
            deleteRecord(phone);
            sortInvertedIndex();
        }
        else if (line[0] == 'q' && line[1] == ' ') {
            string phone = line.substr(2);
            queryRecord(phone);
        }
        else if (line[0] == 's' && line[1] == ' ') {
            string town = line.substr(2);
            invertedIndex->printInvoiceSum(town);
        }
        else if (!(line.compare("e"))) {
            break;
        }
        else if (!(line.compare("min")))
            cout << getMinPhoneNumber() << endl;
        else if (!(line.compare("max")))
            cout << getMaxPhoneNumber() << endl;
        else if (line[0] == 'l' && line[1] == ' ') {
            string dataFile = line.substr(2);
            loadDataFile(dataFile);
        }
        else if (line[0] == 'f' && line[1] == 't' && line[2] == ' ') {
            string town;
            string l;
            std::size_t found = line.find(' ', 3);
            if (found != std::string::npos) {
                town = line.substr(3, found - 3);
                l = line.substr(found + 1);
            }
            else {
                cout << "Usage: ft town l where l is a number" << endl;
                continue;
            }

            if (l.find_first_not_of("0123456789") != std::string::npos) {
                cout << "Usage: \"ft town l\" where l is a number" << endl;
                continue;
            }

            invertedIndex->printTownTopSpenders(town, atoi(l.c_str()));
        }
        else if (line[0] == 't' && line[1] == ' ') {
            string k = line.substr(2);
            if (k.find_first_not_of("0123456789") != std::string::npos) {
                cout << "Usage: \"t k\" where k is a number" << endl;
                continue;
            }
            invertedIndex->printTopTowns(atoi(k.c_str()));
        }
        else if (line[0] == 'p' && line[1] == ' ') {
            string town = line.substr(2);
            invertedIndex->printPopulation(town);
        }
        else if (!(line.compare("fts"))) {
            invertedIndex->printTopSpenderPerTown();
        }
        else
            cout << "Invalid command" << endl;
        cout << endl;
    }
}