#include <iostream>
#include "TownNode.hpp"

using namespace std;

TownNode::TownNode(string town) {
    this->town = town;
    this->head = nullptr;
    this->population = 0;
    this->next = nullptr;
}

string TownNode::getTown() {
    return this->town;
}

TownNode* TownNode::getNext() {
    return next;
}

void TownNode::setNext(TownNode *townNode) {
    this->next = townNode;
}

void TownNode::addRecord(Record *record) {
    if (head == nullptr) {
        head = new RecordPointer(record);
        head->next = nullptr;
        head->previous = nullptr;
        this->population++;
    }
    else {
        RecordPointer *current = head;
        while (record->getInvoice() < current->getRecord()->getInvoice()) {
            if (current->next == nullptr) {
                current->next = new RecordPointer(record);
                current->next->previous = current;
                current->next->next = nullptr;
                this->population++;
                return;
            }
            current = current->next;

        }

        RecordPointer *newNode = new RecordPointer(record);
        if (current == head)
            head = newNode;
        if (current->previous != nullptr)
            current->previous->next = newNode;
        newNode->previous = current->previous;
        current->previous = newNode;
        newNode->next = current;
        this->population++;
    }
}

void TownNode::printPopulation() {
    cout << this->town << ":" << this->population << endl;
}

void TownNode::printTownTopSpenders(int l) {
    RecordPointer *current = head;
    while (current != nullptr && l > 0) {
        cout << current->getRecord()->getPhone() << " " << current->getRecord()->getInvoice() << endl;
        current = current->next;
        l--;
    }
}