#include <iostream>
#include "RecordPointer.hpp"

RecordPointer::RecordPointer(Record *record) {
    this->record = record;
}

RecordPointer::~RecordPointer() {
    delete this->record;
}

void RecordPointer::setNext(RecordPointer *recordPointer) {
    this->next = recordPointer;
}

RecordPointer* RecordPointer::getNext() {
    return this->next;
}

Record* RecordPointer::getRecord() {
    return this->record;
}