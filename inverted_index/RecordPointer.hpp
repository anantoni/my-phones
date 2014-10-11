#ifndef RECORD_POINTER_HPP
#define RECORD_POINTER_HPP

#include "../record/Record.hpp"

class RecordPointer {
    friend class TownNode;
private:
    Record* record;
    RecordPointer *next;
    RecordPointer *previous;

public:
    RecordPointer(Record *record);
    ~RecordPointer();
    void setNext(RecordPointer* recordPointer);
    RecordPointer* getNext();
    Record* getRecord();
};
#endif