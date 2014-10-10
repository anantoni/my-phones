#ifndef HASH_HPP
#define HASH_HPP
#include <stdlib.h>
#include <iostream>
#include "Bucket.hpp"
#include "../inverted_index/InvertedIndexList.hpp"

class Hash {
private:
    int bucketNumber, min, max;
    Bucket **bucketList;

public:
    Hash(int bucketNumber);
    ~Hash();
    int selectBucket(string phone);
    bool addRecord(Record *record);
    void printFirstNames();
    void loadDataFile(string dataFile, InvertedIndexList *invertedIndex);
    string getMinPhoneNumber();
    string getMaxPhoneNumber();

};

#endif