//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "MyReservation.h"
#include "Serial.h"
#include <iostream>

Customer *MyReservation::getCustomer() {
    return customer;
}

Flight *MyReservation::getFlight() {
    return flight;
}

Classes MyReservation::getClass() {
    return cls;
}

int MyReservation::getMaxBaggage() {
    return maxBaggage;
}

string MyReservation::getID() {
    return ID;
}

void MyReservation::createReservation(Collection* collection){
    Flight* f = this->getFlight();
    if (collection->isBusy(f)) {throw "Flight is full!";}
}

MyReservation::MyReservation(string &customerId, string &flightId, Classes cls, int max_baggage, Collection* collection) {
    this->customer = collection->getCustomer(customerId);
    this-> flight = collection->getFlight(flightId);
    this->cls = cls;
    this->maxBaggage = max_baggage;
    this->ID = Serial::serial();
    createReservation(collection);
}

MyReservation::MyReservation(string &id,string &customerId, string &flightId, Classes cls, int max_baggage, Collection* collection) {
    //cout<< flightId << " "<< customerId << "end"<<endl;
    this->ID = id;
    this->customer = collection->getCustomer(customerId);
    this-> flight =collection->getFlight(flightId);
    this->cls = cls;
    this->maxBaggage = max_baggage;
    createReservation(collection);

}