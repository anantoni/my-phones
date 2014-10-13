#include <iostream>
#include "RecordPointer.hpp"

RecordPointer::RecordPointer(Record *record) {
    this->record = record;
}

RecordPointer::~RecordPointer() {
    cout << "Record pointer deleted" << endl;
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