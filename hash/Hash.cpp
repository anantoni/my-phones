#include "Hash.hpp"

Hash::Hash(int bucketNumber) {
    this->bucketNumber = bucketNumber;
    if ((bucketList = new Bucket*[bucketNumber]) == nullptr) {
        cerr << "Error in bucket list allocation" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < bucketNumber; i++)
        bucketList[i] = new Bucket();
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
            if (bucketList[i]->pushBack(record) == true)
                cout << "Record added successfully" << endl;
            else
                cout << "Record not added: Duplicate phone number exists" << endl;
        }
    }
}