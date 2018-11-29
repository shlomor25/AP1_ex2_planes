//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "MyCustomer.h"
#include "Serial.h"

string MyCustomer::getFullName() {
    return fullName;
}

int MyCustomer::getPriority() {
    return priority;
}

list<Reservation *> MyCustomer::getReservations() {
    return reservations;
}

string MyCustomer::getID() {
    return this->ID;
}

void MyCustomer::searchReservation(Collection* collection){
    for (auto &r : collection->getReservations()){
        if (r->getCustomer()->getID() == this->getID()){
            this->reservations.push_back(r);
        }
    }
}

MyCustomer::MyCustomer(string &fullname, int priority, Collection* collection) {
    this->fullName = fullname;
    this->priority = priority;
    this->ID = Serial::serial();
    searchReservation(collection);
}

MyCustomer::MyCustomer(string &id, string &fullname, int priority, Collection* collection) {
    this->fullName = fullname;
    this->priority = priority;
    this->ID = id;
    searchReservation(collection);
}