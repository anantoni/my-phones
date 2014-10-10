#include <iostream>
#include "InvertedIndexList.hpp"

InvertedIndexList::InvertedIndexList() {
    head = nullptr;
}

InvertedIndexList::~InvertedIndexList() {
    cout << "Inverted index list destroyed" << endl;
}

void InvertedIndexList::addRecord(Record *record) {
    if (head == nullptr) {
        head = new TownNode(record->getTown());
        head->setNext(nullptr);
    }
    else {
        if (!(head->getTown().compare(record->getTown())))
            head->addRecord(record);
        else
            addRecord(head->getNext(), record);
    }
}

void InvertedIndexList::addRecord(TownNode *tail, Record *record) {
    if (tail == nullptr) {
        tail = new TownNode(record->getTown());
        tail->setNext(nullptr);
    }
    else {
        if (!(tail->getTown().compare(record->getTown())))
            tail->addRecord(record);
        else
            addRecord(tail->getNext(), record);
    }
}

void InvertedIndexList::printPopulations() {
    if (head == nullptr)
        return;
    TownNode *current = head;
    while (current->getNext() != nullptr) {
        current->printPopulation();
        current = current->getNext();
    }
    current->printPopulation();
}