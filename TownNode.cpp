#include <iostream>
#include "TownNode.hpp"

using namespace std;

TownNode::TownNode(string town) {
    this->town = town;
    this->head = nullptr;
    this->population = 0;
    this->next = nullptr;
    this->invoiceSum = 0.0;
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

void TownNode::clean() {
    RecordPointer *current = head;
    RecordPointer *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

TownNode::~TownNode() {}

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
    RecordPointer *toBeAdded = new RecordPointer(record);
    if (head == nullptr ||  head->getRecord()->getInvoice() < record->getInvoice()) {
        toBeAdded->next = head;
        head = toBeAdded;
    }
    else {
        RecordPointer *current = head;
        while (current->next != nullptr && current->next->getRecord()->getInvoice() >= record->getInvoice())
            current = current->next;

        toBeAdded->next = current->next;
        current->next = toBeAdded;

    }
    this->population++;
    this->invoiceSum += record->getInvoice();
    return;

}

void TownNode::deleteRecord(string phone) {

    if (!(head->getRecord()->getPhone().compare(phone))) {
        RecordPointer *next = head->next;
        this->invoiceSum -= head->getRecord()->getInvoice();
        delete head;
        head = next;
        this->population--;
        return;
    }

    RecordPointer *current = head;
    while (current->next != nullptr) {
        if (!(current->next->getRecord()->getPhone().compare(phone))) {
            RecordPointer *next = current->next;
            current->next = next->next;
            this->invoiceSum -= next->getRecord()->getInvoice();
            delete next;
            this->population--;
            return;
        }
        current = current->next;
    }
}

void TownNode::printPopulation() {
    cout << this->town << ": " << this->population << endl;
}

void TownNode::printTownTopSpenders(int l) {
    RecordPointer *current = head;
    if (current == nullptr) {
        cout << "No records found for given town" << endl;
        return;
    }

    while (current != nullptr && l > 0) {
        cout << current->getRecord()->getPhone() << " " << current->getRecord()->getInvoice() << endl;
        current = current->next;
        l--;
    }
}

void TownNode::printInvoiceSum() {
    cout << this->town << ": " << this->invoiceSum << endl;
}


