#ifndef INVERTED_INDEX_NODE_HPP
#define INVERTED_INDEX_NODE_HPP

#include "../record/Record.hpp"
#include "RecordPointer.hpp"

class TownNode {
private:
    string town;
    RecordPointer *head;
    int population;
    TownNode *next;
public:
    TownNode(string town);
    ~TownNode();
    void addRecord(Record *record);
    void addRecord(RecordPointer *tail, Record *record);
    string getTown();
    void setNext(TownNode *townNode);
    TownNode* getNext();
};
#endif