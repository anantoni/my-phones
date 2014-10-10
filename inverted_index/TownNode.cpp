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
        head->setNext(nullptr);
    }
    else
        addRecord(head->getNext(), record );

}

void TownNode::addRecord(RecordPointer *tail, Record *record) {
    if (tail == nullptr) {
        head = new RecordPointer(record);
        head->setNext(nullptr);
    }
    else
        addRecord(tail->getNext(), record);
}
