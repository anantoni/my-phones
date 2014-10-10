#ifndef HASH_HPP
#define HASH_HPP

#include "Bucket.hpp"

class Hash {
private:
    int bucketNumber;
    Bucket **bucketList;
public:
    Hash(int bucketNumber);
    ~Hash();
    int selectBucket(string phone);
    void addRecord(Record &record);
};

#endif