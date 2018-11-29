//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include <iostream>
#include "MyEmployee.h"
#include "Serial.h"

int MyEmployee::getSeniority() {
    return seniority;
}

Employee *MyEmployee::getEmployer() {
    return employer;
}

int MyEmployee::getBirthYear() {
    return birthYear;
}

Jobs MyEmployee::getTitle() {
    return title;
}

string MyEmployee::getID() {
    return ID;
}

MyEmployee::MyEmployee(int seniority, int birthYear, string employerID, Jobs title, Collection* collection) {
    this->seniority = seniority;
    this->birthYear = birthYear;
    this->title = title;
    this->ID = Serial::serial();
    this->employer = collection->getEmployee(employerID);
}
/*
MyEmployee::MyEmployee(string id, Collection* collection) {
    this->seniority = collection->getEmployee(id)->getSeniority();
    this->birthYear = collection->getEmployee(id)->getBirthYear();
    this->title = collection->getEmployee(id)->getTitle();
    this->ID = id;
    this->employer = collection->getEmployee(id)->getEmployer();
}*/

MyEmployee::MyEmployee(int seniority, int birthYear, string employerID, Jobs title, string id, Collection* collection) {
    this->seniority = seniority;
    this->birthYear = birthYear;
    this->title = title;
    this->ID = id;
    this->employer = collection->getEmployee(employerID);
}
