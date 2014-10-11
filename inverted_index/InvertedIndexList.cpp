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

void InvertedIndexList::deleteRecord(string town, string phone) {
    TownNode *current = head;

    while (current != nullptr) {
        if (!(current->getTown().compare(town)))
            current->deleteRecord(phone);
        current = current->next;
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

void InvertedIndexList::printTownTopSpenders(string town, int l) {
    TownNode *current = head;
    while (current != nullptr) {
        if (!(current->getTown().compare(town))) {
            current->printTownTopSpenders(l);
            return;
        }
        else
            current = current->next;
    }
    cout << "No records found for given town." << endl;
}

void InvertedIndexList::printPopulation(string town) {
    TownNode *current = head;
    while (current != nullptr) {
        if (!(current->getTown().compare(town))) {
            current->printPopulation();
            return;
        }
        else
            current = current->next;
    }
    cout << "No records found for given town." << endl;
}

void InvertedIndexList::printInvoiceSum(string town) {
    TownNode *current = head;

    while (current != nullptr) {
        if (!(current->getTown().compare(town))) {
            current->printInvoiceSum();
            return;
        }
        else
            current = current->next;
    }
    cout << "No records found for given town." << endl;
}

void InvertedIndexList::sort() {
    TownNode *current = head;
    TownNode *next = head->next;

    while(current != nullptr){
        while(next != nullptr){
            if(next->population > current->population) {
                TownNode temp(*current);
                *current = *next;
                *next = temp;
            }
            next = next->next;
        }

        if ((current = current->next) == nullptr)
            return;
        next = current->next;
    }
}

void InvertedIndexList::printTopTowns(int k) {
    TownNode *current = head;

    while (current != nullptr && k > 0) {
        cout << current->getTown() << ": " << current->population << endl;
        k--;
        current = current->next;
    }
}