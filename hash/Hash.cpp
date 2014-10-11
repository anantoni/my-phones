#include <sstream>
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
    cout << "Hash Destroyed" << endl;
}

int Hash::selectBucket(string phone) {
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(phone);

    return str_hash%bucketNumber;
}

bool Hash::addRecord(Record *record) {
    int bucketSelection = selectBucket(record->getPhone());
    cout << "Bucket selected: " << bucketSelection << endl;

    if (bucketList[bucketSelection]->pushBack(record) == true) {
        cout << "Phone number " << record->getPhone() << " added successfully" << endl;
        invertedIndex->addRecord(record);

        long phone = atol(record->getPhone().c_str());
        cout << phone << endl;
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
        cout << "wtf" << endl;
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
        cerr << "Cannot open binary file " << dataFile << endl;
        exit(EXIT_FAILURE);
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
        printf("%s %s %s %s %-5.2f\n", rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
        Record *record = new Record(rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
        this->addRecord(record);
    }
    fclose (fpb);
    invertedIndex->sort();
    invertedIndex->printPopulations();
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
        cout << bucketMax << endl;
        if (bucketMax != -1 && bucketMax > max)
            max = bucketMax;
    }
}

void Hash::sortInvertedIndex() {
    this->invertedIndex->sort();
}