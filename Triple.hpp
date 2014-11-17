#ifndef TRIPLE_HPP
#define TRIPLE_HPP
#include <iostream>
using namespace std;

class Triple {
private:
    string town;
    string phoneno;
    float invoice;
    Triple *next;
    Triple *previous;
    friend class InvertedIndexList;
public:
    Triple(string town, string phoneno, float invoice);
};

#endif