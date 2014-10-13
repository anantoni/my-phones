#include <iostream>
#include "Bucket.hpp"

Bucket::Bucket() {
    head = nullptr;
}

Bucket::~Bucket() {
//    Record* current = head;
//    Record* next = nullptr;
//    while (current!= nullptr) {
//        next = current->next;
//        delete current;
//        current = next;
//    }
}

bool Bucket::pushBack(Record* record) {
    if (head == nullptr) {
        head = record;
        record->next = nullptr;
        return true;
    }
    else {
        if (!(head->getPhone().compare(record->getPhone())))
            return false;
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
        if (!((*tail)->getPhone().compare(record->getPhone())))
            return false;
        return pushBack(&((*tail)->next), record);
    }
}

void Bucket::queryRecord(string phone) {
    Record* current = head;
    while (current != nullptr) {
        if (!(current->getPhone().compare(phone))) {
            cout << current->getPhone() << " " << current->getFirstName() << " " << current->getLastName() << " " << current->getTown() << " " << current->getInvoice() << endl;
            return;
        }
        current = current->next;
    }
    cout << "Phone number not found " << endl;
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

string Bucket::deleteRecord(string phone) {
    if (head == nullptr)
        return "";

    Record *current = head;
    if (!(head->getPhone().compare(phone))) {
        string town = head->getTown();
        head = current->next;
        return town;
    }

    while (current->next != nullptr) {
        if (!(current->next->getPhone().compare(phone))) {
            string town = current->next->getTown();
            current->next = current->next->next;
            return town;
        }
        current = current->next;
    }
    return "";
}

long Bucket::getBucketMin() {
    Record *current = head;

    if (current == nullptr)
        return -1;

    long min = atol(head->getPhone().c_str());
    while (current != nullptr) {
        long phone = atol(current->getPhone().c_str());
        if (phone < min)
            min = phone;
        current = current->next;
    }

    return min;
}

long Bucket::getBucketMax() {
    Record *current = head;

    if (current == nullptr)
        return -1;

    long max = atol(head->getPhone().c_str());
    while (current != nullptr) {
        long phone = atol(current->getPhone().c_str());
        if (phone > max)
            max = phone;
        current = current->next;
    }

    return max;

}