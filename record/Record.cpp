#include <iostream>
#include "Record.hpp"

Record::Record(string phone, string firstName, string lastName,
        string town, float invoice) {

    this->phone = phone;
    this->lastName = lastName;
    this->firstName = firstName;
    this->town = town;
    this->invoice = invoice;
    this->next = nullptr;
}

Record::Record(char *phone, char *lastName, char *firstName,
        char *town, float invoice) {

    this->phone = phone;
    this->lastName = lastName;
    this->firstName = firstName;
    this->town = town;
    this->invoice = invoice;
    this->next = nullptr;
}

Record::~Record() {
    cout << "Record destroyed" << endl;
}

void Record::setPhone(string phone) {
    this->phone = phone;
}

void Record::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Record::setLastName(string lastName) {
    this->lastName = lastName;
}

void Record::setTown(string town) {
    this->town = town;
}

void Record::setInvoice(float invoice) {
    this->invoice = invoice;
}

void Record::setNext(Record *next) {
    this->next = next;
}

string Record::getPhone() {
    return this->phone;
}

string Record::getLastName() {
    return this->lastName;
}

string Record::getFirstName() {
    return this->firstName;
}

string Record::getTown() {
    return this->town;
}
float Record::getInvoice() {
    return this->invoice;
}

Record* Record::getNext() {
    return this->next;
}



