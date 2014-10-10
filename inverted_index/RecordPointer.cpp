#include "RecordPointer.hpp"

RecordPointer::RecordPointer(Record *record) {
    this->record = record;
}

void RecordPointer::setNext(RecordPointer *recordPointer) {
    this->next = recordPointer;
}

RecordPointer* RecordPointer::getNext() {
    return this->next;
}