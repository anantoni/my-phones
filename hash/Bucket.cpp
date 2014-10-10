#include <iostream>
#include "Bucket.hpp"

Bucket::Bucket() {
    head = nullptr;
}

bool Bucket::pushBack(Record* record) {
    if (head == nullptr) {
        head = record;
        record->setNext(nullptr);
        return true;
    }
    else {
        if (!(head->getPhone().compare(record->getPhone()))) {
            cout << "Bucket::pushBack(Record &record) " << head->getPhone() << " " << record->getPhone() << endl;
            return false;
        }
        return pushBack(head->getNext(), record);
    }
}

bool Bucket::pushBack(Record *tail, Record* record) {
    if (tail == nullptr) {
        tail = record;
        record->setNext(nullptr);
        return true;
    }
    else {
        if (!(tail->getPhone().compare(record->getPhone()))) {
            cout << "Bucket::pushBack(Record *tail, RecordRecord &record) " << tail->getPhone() << " " << record->getPhone() << endl;
            return false;
        }
        return pushBack(head->getNext(), record);
    }
}