//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include <iostream>
#include "MyFlight.h"
#include "Serial.h"

MyFlight::MyFlight(int model_number, Date date, string &source, string &destination, Collection* collection) : date(date) {
    this->modelNumber = model_number;
    this->date = date;
    this->source = source;
    this->destination = destination;
    this->ID = Serial::serial();
    createCrew(collection);
}

MyFlight::MyFlight(string &id, int model_number, Date date, string &source, string &destination, Collection* collection): date(date) {
    this->modelNumber = model_number;
    this->date = date;
    this->source = source;
    this->destination = destination;
    this->ID = id;
}


void MyFlight::createCrew(Collection* collection){
    int numOfCrew;
    // create crew for flight: search free employees as num of crew
    Plane* p = collection->getPlane(this->getModelNumber(), this->getDate());

    for (auto &c : p->getCrewNeeded()) {
        numOfCrew = c.second;
        for (auto &e : collection->getEmployees()) {
            if (e->getTitle() == c.first && !collection->isBusy(e, this->date) && numOfCrew > 0) {
                this->assignedCrew.push_back(e);
                numOfCrew--;
                // cout << "num of crew:" <<numOfCrew << endl;
            }
        }
        if (numOfCrew > 0) {
            throw "no enough employees!"; }
    }
}

int MyFlight::getModelNumber() {
    return modelNumber;
}

Date MyFlight::getDate() {
    return date;
}

list<Employee *> MyFlight::getAssignedCrew() {
    return assignedCrew;
}

list<Reservation *> MyFlight::getReservations() {
    return reservations;
}

string MyFlight::getSource() {
    return source;
}

string MyFlight::getDestination() {
    return destination;
}

string MyFlight::getID() {
    return this->ID;
}