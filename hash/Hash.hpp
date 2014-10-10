#ifndef HASH_HPP
#define HASH_HPP
#include <stdlib.h>
#include <iostream>
#include "Bucket.hpp"

class Hash {
private:
    int bucketNumber;
    Bucket **bucketList;
public:
    Hash(int bucketNumber);
    ~Hash();
    int selectBucket(string phone);
    bool addRecord(Record *record);
};

#endif