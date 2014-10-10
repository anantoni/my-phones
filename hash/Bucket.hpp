#ifndef BUCKET_HPP
#define BUCKET_HPP

#include "../record/Record.hpp"
class Record;

class Bucket {
private:
    Record* head;
public:
    Bucket();
    bool pushBack(Record *record);
    bool pushBack(Record **tail, Record *record);
    void printAllFirstNames();
};

#endif