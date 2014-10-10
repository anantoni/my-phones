#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>
using namespace std;

class Record {
private:
    string phone;
    string firstName;
    string lastName;
    string town;
    float invoice;
    Record *next;

public:
    Record(string phone, string lastName, string firstName,
            string town, float invoice);
    Record(char* phone, char* lastName, char* firstName,
            char* town, float invoice);
    ~Record();
    void setPhone(string phone);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setTown(string town);
    void setInvoice(float invoice);
    void setNext(Record* next);

    string getPhone();
    string getFirstName();
    string getLastName();
    string getTown();
    float getInvoice();
    Record* getNext();
};

#endif