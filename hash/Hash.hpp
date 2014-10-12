#ifndef HASH_HPP
#define HASH_HPP
#include <stdlib.h>
#include <iostream>
#include "Bucket.hpp"
#include "../inverted_index/InvertedIndexList.hpp"

class Hash {
private:
    int bucketNumber;
    long min, max;
    Bucket **bucketList;
    InvertedIndexList *invertedIndex;

public:
    Hash(int bucketNumber, InvertedIndexList *invertedIndex);
    ~Hash();
    int selectBucket(string phone);
    bool addRecord(Record *record);
    bool deleteRecord(string phone);
    void queryRecord(string phone);
    void printFirstNames();
    void loadDataFile(string dataFile);
    long getMinPhoneNumber();
    long getMaxPhoneNumber();
    void updateMin();
    void updateMax();
    void sortInvertedIndex();
    void readFromStream(istream &is);
};

#endif