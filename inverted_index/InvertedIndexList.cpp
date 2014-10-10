#include <iostream>
#include "InvertedIndexList.hpp"

InvertedIndexList::InvertedIndexList() {
    head = nullptr;
}

InvertedIndexList::~InvertedIndexList() {
    cout << "Inverted index destroyed" << endl;
}

void InvertedIndexList::addRecord(Record *record) {
    if (head == nullptr) {
        head = new TownNode(record->getTown());
        head->next = nullptr;
        head->addRecord(record);
    }
    else {
        if (!(head->getTown().compare(record->getTown())))
            head->addRecord(record);
        else
            addRecord(&(head->next), record);
    }
}

void InvertedIndexList::addRecord(TownNode **tail, Record *record) {
    if (*tail == nullptr) {
        *tail = new TownNode(record->getTown());
        (*tail)->next = nullptr;
        (*tail)->addRecord(record);
    }
    else {
        if (!((*tail)->getTown().compare(record->getTown())))
            (*tail)->addRecord(record);
        else
            addRecord(&(*tail)->next, record);
    }
}

void InvertedIndexList::printPopulations() {
    if (head == nullptr)
        return;
    TownNode *current = head;
    cout << current->getNext() << endl;
    while (current->getNext() != nullptr) {
        current->printPopulation();
        current = current->getNext();
    }
    current->printPopulation();
}

