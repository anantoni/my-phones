#include "Bucket.hpp"

Bucket::Bucket() {
    head = nullptr;
}

bool Bucket::pushBack(Record &record) {
    if (head == nullptr) {
        head = &record;
        return true;
    }
    else {
        if (!(head->getPhone().compare(record.getPhone())))
            return false;
        return pushBack(head->getNext(), record);
    }
}

bool Bucket::pushBack(Record *tail, Record &record) {
    if (tail == nullptr) {
        tail = &record;
        return true;
    }
    else {
        if (!(head->getPhone().compare(record.getPhone())))
            return false;
        return pushBack(head->getNext(), record);
    }
}