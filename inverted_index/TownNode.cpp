#include <iostream>
#include "TownNode.hpp"

using namespace std;

TownNode::TownNode(string town) {
    this->town = town;
    this->head = nullptr;
    this->population = 0;
    this->next = nullptr;
    this->invoiceSum;
}

TownNode::TownNode(const TownNode &node) {
    this->town = node.town;
    this->head = node.head;
    this->population = node.population;
    this->next = node.next;
    this->invoiceSum = node.invoiceSum;
}

TownNode &TownNode::operator=(const TownNode &node) {
    this->town = node.town;
    this->head = node.head;
    this->population = node.population;
    this->invoiceSum = node.invoiceSum;

    return *this;
}

TownNode::~TownNode() {
    cout << "Town node destroyed" << endl;
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
        this->invoiceSum += record->getInvoice();
    }
    else {
        RecordPointer *current = head;
        while (record->getInvoice() < current->getRecord()->getInvoice()) {
            if (current->next == nullptr) {
                current->next = new RecordPointer(record);
                current->next->previous = current;
                current->next->next = nullptr;
                this->population++;
                this->invoiceSum += record->getInvoice();
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
        this->invoiceSum += record->getInvoice();
    }
}

void TownNode::deleteRecord(string phone) {
    RecordPointer *current = head;
    int counter = 0;

    while (current != nullptr) {
        if (!(current->getRecord()->getPhone().compare(phone))) {
            if (counter == 0)
                head = current->next;
            else {
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }
            this->invoiceSum -= current->getRecord()->getInvoice();
            delete current;
        }
        counter++;
        current = current->next;
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

void TownNode::printInvoiceSum() {
    cout << this->town << ": " << this->invoiceSum << endl;
}


