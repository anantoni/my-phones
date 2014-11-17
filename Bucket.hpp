#ifndef BUCKET_HPP
#define BUCKET_HPP

#include "Record.hpp"
class Record;

class Bucket {
private:
    Record* head;
public:
    Bucket();
    ~Bucket();
    bool pushBack(Record *record);
    bool pushBack(Record **tail, Record *record);
    void printAllFirstNames();
    void queryRecord(string phone);
    string deleteRecord(string phone);
    long getBucketMin();
    long getBucketMax();
};

#endif