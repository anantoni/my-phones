#ifndef INVERTED_INDEX_LIST_HPP
#define INVERTED_INDEX_LIST_HPP
#include "TownNode.hpp"

class TownNode;

class InvertedIndexList {
private:
    TownNode *head;
public:
    InvertedIndexList();
    ~InvertedIndexList();
    void addRecord(Record *record);
    void addRecord(TownNode **tail, Record *record);
    void printPopulations();
    void sort();
    void printTownTopSpenders(string town, int l);
    void printPopulation(string town);
    void deleteRecord(string town, string phone);
    void printInvoiceSum(string town);
};
#endif