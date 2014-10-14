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

void TownNode::clean() {
    RecordPointer *current = head;
    RecordPointer *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

TownNode::~TownNode() {
//    cout << "Town node destroyed" << endl;
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



/*if (topList == nullptr || topList->invoice < triple->invoice) {
    triple->next = topList;
    topList = triple;
  }
  else {
    currentTop = topList;
    while (currentTop->next != nullptr && currentTop->next->invoice >= triple->invoice) {
        currentTop = currentTop->next;
  }
  triple->next = currentTop->next;
  currentTop->next = triple;
}*/
void TownNode::addRecord(Record *record) {
    RecordPointer *toBeAdded = new RecordPointer(record);
    if (head == nullptr ||  head->getRecord()->getInvoice() < record->getInvoice()) {
        toBeAdded->next = head;
        head = toBeAdded;
        this->population++;
        this->invoiceSum += record->getInvoice();
        return;
    }

    RecordPointer *current = head;
    while (current->next != nullptr && current->getRecord()->getInvoice() >= record->getInvoice())
        current = current->next;

    current->next = new RecordPointer(record);
    current->next->previous = current;
    current->next->next = nullptr;
    this->population++;
    this->invoiceSum += record->getInvoice();
    return;

}

void TownNode::deleteRecord(string phone) {

    cout << head->getRecord()->getPhone() << endl;
    if (!(head->getRecord()->getPhone().compare(phone))) {
        RecordPointer *next = head->next;
        delete head;
        head = next;
        return;
    }

    RecordPointer *current = head;
    while (current->next != nullptr) {
        if (!(current->next->getRecord()->getPhone().compare(phone))) {
            RecordPointer *next = current->next;
            current->next = next->next;
            delete next;
        }
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


