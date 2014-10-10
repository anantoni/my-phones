#ifndef INVERTED_INDEX_LIST_HPP
#define INVERTED_INDEX_LIST_HPP

#include "TownNode.hpp"

class InvertedIndexList {
private:
    TownNode *head;
public:
    InvertedIndexList();
    ~InvertedIndexList();
    void addRecord(Record *record);
    void addRecord(TownNode *tail, Record *record);
};
#endif