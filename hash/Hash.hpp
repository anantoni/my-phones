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
    InvertedIndexList *invertedIndex;

public:
    Hash(int bucketNumber, InvertedIndexList *invertedIndex);
    ~Hash();
    int selectBucket(string phone);
    bool addRecord(Record *record);
    void printFirstNames();
    void loadDataFile(string dataFile);
    int getMinPhoneNumber();
    int getMaxPhoneNumber();
};

#endif