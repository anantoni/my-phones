#include "Hash.hpp"
#include "../record/myRecord.hpp"

Hash::Hash(int bucketNumber) {
    this->bucketNumber = bucketNumber;
    if ((bucketList = new Bucket*[bucketNumber]) == nullptr) {
        cerr << "Error in bucket list allocation" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < bucketNumber; i++)
        bucketList[i] = new Bucket();

    min = 0;
    max = 0;
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
    for (int i = 0; i < bucketNumber; i++) {
        if (bucketSelection == i) {
            cout << "Selected bucket: " << bucketSelection << endl;
            if (bucketList[i]->pushBack(record) == true) {
                cout << "Record added successfully" << endl;
                int phoneno = atoi(record->getPhone().c_str());
                if (phoneno > max)
                    max = phoneno;
                if (phoneno < min)
                    min = phoneno;
                return true;
            }
            else {
                cout << "Record not added: Duplicate phone number exists" << endl;
                return false;
            }
        }
    }
}

void Hash::printFirstNames() {
    for (int i = 0; i < bucketNumber; i++) {
        bucketList[i]->printAllFirstNames();
    }
}

void Hash::loadDataFile(string dataFile, InvertedIndexList *invertedIndex) {
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

    cout << "Records found in file " << numOfrecords << endl;
    for (int i = 0; i < numOfrecords; i++) {
        fread(&rec, sizeof(rec), 1, fpb);
        printf("%s %s %s %s %-5.2f\n", rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
        Record *record = new Record(rec.phone, rec.LastName, rec.FirstName, rec.Town, rec.invoice);
        if (this->addRecord(record))
            invertedIndex->addRecord(record);
    }
    fclose (fpb);

}