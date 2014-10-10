#include <iostream>
#include "Bucket.hpp"

Bucket::Bucket() {
    head = nullptr;
}

bool Bucket::pushBack(Record* record) {
    if (head == nullptr) {
        head = record;
        record->next = nullptr;
        return true;
    }
    else {
        if (!(head->getPhone().compare(record->getPhone()))) {
            cout << "Bucket::pushBack(Record &record) " << head->getPhone() << " " << record->getPhone() << endl;
            return false;
        }
        return pushBack(&(head->next), record);
    }
}

bool Bucket::pushBack(Record **tail, Record* record) {
    if ((*tail) == nullptr) {
        (*tail) = record;
        record->next = nullptr;
        return true;
    }
    else {
        if (!((*tail)->getPhone().compare(record->getPhone()))) {
            cout << "Bucket::pushBack(Record *tail, RecordRecord &record) " << (*tail)->getPhone() << " " << record->getPhone() << endl;
            return false;
        }
        return pushBack(&((*tail)->next), record);
    }
}

void Bucket::printAllFirstNames() {
    if (head == nullptr)
        return;

    Record *current = head;
    while (current->getNext() != nullptr) {
        cout << current->getFirstName() << endl;
        current = current->getNext();
    }
    cout << current->getFirstName() << endl;
}