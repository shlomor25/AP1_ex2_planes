//
//Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "MyPlane.h"
#include "Serial.h"

MyPlane::MyPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers, Collection* collection) {
    this->modelNumber = model_number;
    this->crewNeeded = crew_needed;
    this->maxFirstClass = max_passangers.at(FIRST_CLASS);
    this->maxEconomyClass = max_passangers.at(SECOND_CLASS);
    this->ID = Serial::serial();
}

MyPlane::MyPlane(string id, int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers, Collection* collection) {
    this->modelNumber = model_number;
    this->crewNeeded = crew_needed;
    this->maxFirstClass = max_passangers.at(FIRST_CLASS);
    this->maxEconomyClass = max_passangers.at(SECOND_CLASS);
    this->ID = id;
}

int MyPlane::getModelNumber() {
    return modelNumber;
}

map<Jobs, int> MyPlane::getCrewNeeded() {
    return crewNeeded;
}

int MyPlane::getMaxFirstClass() {
    return maxFirstClass;
}

int MyPlane::getMaxEconomyClass() {
    return maxEconomyClass;
}

string MyPlane::getID() {
    return ID;
}