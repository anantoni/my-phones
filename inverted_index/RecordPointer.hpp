#ifndef RECORD_POINTER_HPP
#define RECORD_POINTER_HPP

#include "../record/Record.hpp"

class RecordPointer {
private:
    Record* record;
    RecordPointer* next;

public:
    RecordPointer(Record *record);
    ~RecordPointer();
    void setNext(RecordPointer* recordPointer);
    RecordPointer* getNext();
};
#endif