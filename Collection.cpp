//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "Collection.h"
#include "MyCustomer.h"
#include "MyFlight.h"
#include "MyPlane.h"
#include "MyReservation.h"
#include "MyEmployee.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>


list<Reservation *> Collection::getReservations() {
    return reservations;
}

list<Plane *> Collection::getPlanes() {
    return planes;
}

list<Employee *> Collection::getEmployees() {
    return employees;
}

list<Flight *> Collection::getFlights() {
    return flights;
}

list<Customer *> Collection::getCustomers() {
    return customers;
}

Reservation *Collection::getReservation(string reservationID) {
    for (auto &res : this->reservations) {
        if(res->getID() == reservationID)
            return res;
    }
    return nullptr;
}

Plane *Collection::getPlane(string planeID) {
    for (auto &plane: this->planes) {
        if(plane->getID() == planeID)
            return plane;
    }
    return nullptr;
}

Plane *Collection::getPlane(int modelNumber, Date date) {
    for (auto &plane: this->planes) {
        if(plane->getModelNumber() == modelNumber && !isBusy(plane, date))
            return plane;
    }
    throw "sorry, your plane in air";
}

Employee *Collection::getEmployee(string employeeID) {
    for (auto &emp : this->employees) {

        if(emp->getID() == employeeID)
            return emp;
    }
    //cout<<"aaaaaaa";
    return nullptr;
}

Flight *Collection::getFlight(string flightID) {
    for (auto &flight : this->flights) {
        if(flight->getID() == flightID)
            return flight;
    }
    return nullptr;
}

Customer *Collection::getCustomer(string &customerID) {
    for (auto &customer : this->customers) {
        if(customer->getID() == customerID)
            return customer;
    }
    return nullptr;
}

void Collection::addReservation(Reservation *reservation) {
    this->reservations.push_back(reservation);
}

void Collection::addEmployee(Employee *employee) {
    this->employees.push_back(employee);
}

void Collection::addCustomer(Customer *customer) {
    this->customers.push_back(customer);
}

void Collection::addFlight(Flight *flight) {
    this->flights.push_back(flight);
}

void Collection::addPlane(Plane *plane) {
    this->planes.push_back(plane);
}

void Collection::save() {
    int lineIndex = 1;
    ofstream file_obj("data.txt");
    if(file_obj.is_open()) {

        file_obj << " " << lineIndex++ << "------------------------ Customers--------------------------" << endl;
        // save id, priority, full name (take reservations from other table)
        for (auto &customer : this->customers) {
            // todo change spacebar to "-"
            file_obj << "c" << lineIndex++ << "\t" << customer->getID()
                     << "\t" << customer->getFullName()
                     << "\t" << customer->getPriority() << endl;
        }

        file_obj << " " << lineIndex++ << "------------------------- Employees --------------------------" << endl;

        for (auto &employee : this->employees) {
            file_obj << "e" << lineIndex++ << "\t" << employee->getID();
            file_obj << "\t" << employee->getBirthYear()
                     << "\t" << employee->getTitle()
                     << "\t" << employee->getSeniority();
            if (employee->getEmployer() == nullptr) {
                file_obj << "\thas'nt_employer"<< endl;
            } else {
                file_obj << "\t" << employee->getEmployer()->getID() << endl;
            }
        }

        file_obj << " " << lineIndex++ << "------------------------ Planes--------------------------" << endl;
        // save id, model number, max first class, max economy class, crew needed (length is permanent)
        for (auto &plane : this->planes) {
            file_obj << "p" << lineIndex++ <<  "\t" << plane->getID()
                     << "\t" << plane->getModelNumber()
                     << "\t" << plane->getMaxFirstClass()
                     << "\t" << plane->getMaxEconomyClass() << "\t";
            for(auto &crew : plane->getCrewNeeded()){
                file_obj << (crew.first) << ":" << crew.second << "#";
            }
            file_obj << endl;
        }

        file_obj << " " << lineIndex++ << "------------------------ Flight --------------------------" << endl;
        // save id, date, model number, source, destination (take assigned crew and reservations from other tables)
        for (auto &flight : this->flights) {
            file_obj << "f" << lineIndex++ << "\t" << flight->getID()
                     << "\t" << flight->getDate().getDate()
                     << "\t" << flight->getModelNumber()
                     << "\t" << flight->getSource()
                     << "\t" << flight->getDestination() << endl;
        }

        file_obj << " " << lineIndex++ << "------------------------ Reservations --------------------------" << endl;
        for (auto &reservation : this->reservations) {
            cout << "write_res" <<endl;
            file_obj << "r" << lineIndex++ << "\t" << reservation->getID()
                     << "\t" << reservation->getFlight()->getID()
                     << "\t" << reservation->getCustomer()->getID()
                     << "\t" << reservation->getMaxBaggage()
                     << "\t" << reservation->getClass() << endl;
        }
        file_obj << "EOF" << endl;
        file_obj.close();
    } else {
        throw "can not open file";
    }
}

void Collection::loadEmployee(string line){
    int i = 0;
    int sen = 0;
    string id;
    int birth = 0;
    string employerId;
    Jobs title = OTHER;

    while (line[i++] != '\t');
    // id
    while (line[i] != '\t'){
        id += line[i];
        i++;
    }
    i++;
    // birth
    while (line[i] != '\t'){
        birth *= 10;
        birth += line[i]-'0';
        i++;
    }
    i++;
    // job
    while (line[i] != '\t'){
        title = (Jobs)(line[i] - '0');
        i++;
    }
    i++;
    // seniority
    while (line[i]!='\t'){
        sen*=10;
        sen+=line[i]-'0';
        i++;
    }
    i++;
    // employerId
    while (i<line.length()){
        employerId += line[i];
        i++;
    }
    if (employerId == "has'nt_employer") { employerId = "";
        /*cout<< "no employer"<<endl;*/}
    this->employees.push_back(new MyEmployee(sen, birth, employerId, title, id, this));
}

void Collection::loadCustomer(string line) {
    string id;
    string name;
    int priority = 0;
    int i = 0;

    while (line[i++] != '\t');
    // id
    while (line[i] != '\t') {id += line[i++];}
    i++;
    // name
    while (line[i] != '\t') {name += line[i++];}
    i++;
    // priority
    while (i < line.length()) {
        priority *= 10;
        priority += line[i++] - '0';
    }
    this->customers.push_back(new MyCustomer(id, name, priority, this));
}

void Collection::loadPlane(string line){
    string id;
    int modelNumber = 0;
    map<Classes, int> maxClasses;
    int maxFirst = 0;
    int maxEconomy = 0;
    string job;
    int numJobs;
    map<Jobs, int> crewNeeded;
    int i = 0;

    while (line[i++] != '\t');
    // id
    while (line[i] != '\t') { id += line[i++]; }
    i++;
    // model number
    while (line[i] != '\t') {
        modelNumber *= 10;
        modelNumber += line[i++] - '0';
    }
    i++;
    // find map class to num passengers
    while (line[i] != '\t') {
        maxFirst *= 10;
        maxFirst += line[i++] - '0';
    }
    maxClasses.insert(std::pair<Classes, int>(FIRST_CLASS, maxFirst));
    i++;

    while (line[i] != '\t') {
        maxEconomy *= 10;
        maxEconomy += line[i++] - '0';
    }
    maxClasses.insert(std::pair<Classes, int>(SECOND_CLASS, maxEconomy));
    i++;
    // find map job to num crew needed
    Jobs j;
    while (i < line.length()) {
        job = "";
        while (line[i] != ':') { job += line[i++]; }
        i++;
        numJobs = 0;
        while (line[i] != '#') {
            numJobs *= 10;
            numJobs += line[i++] - '0';
        }
        i++;
        Jobs j = (Jobs)(std::stoi(job)-'0');
        crewNeeded.insert(std::pair<Jobs, int>(j, numJobs));
    }
    this->planes.push_back(new MyPlane(id, modelNumber, crewNeeded, maxClasses, this));
}

void Collection::loadFlight(string line){
    /*   std::istringstream x(line);
       vector<string> y(istream_iterator<string> {x},istream_iterator<string>());
       // todo now in x i get at()*/
    int i = 0;
    string id;
    string date;
    int modelNumber = 0;
    string source;
    string destination;
    while (line[i++] != '\t');
    // id
    while (line[i]!='\t'){id+=line[i++];}
    i++;
    // date
    while (line[i]!='\t'){date+=line[i++];}
    i++;
    // model number
    while (line[i] != '\t') {
        modelNumber *= 10;
        modelNumber += line[i++] - '0';
    }
    i++;
    // source
    while (line[i]!='\t'){source+=line[i++];}
    i++;
    // find destination
    while (i<line.length()){destination+=line[i++];}

    this->flights.push_back(new MyFlight(id, modelNumber, Date(date), source, destination, this));

}

void Collection::loadReservation(string line){
    cout <<"load res"<<endl;
    int i = 0;
    string id;
    string flightID;
    string customerID;
    int modelNumber = 0;
    int cls = 0;
    int maxBaggage = 0;
    while (line[i++]!='\t');
    // id
    while (line[i]!='\t'){id+=line[i++];}
    i++;
    // flight id
    while (line[i]!='\t'){flightID+=line[i++];}
    i++;
    // customer id
    while (line[i]!='\t'){customerID+=line[i++];}
    i++;
    // max baggage
    while (line[i]!='\t') {
        maxBaggage *= 10;
        maxBaggage += line[i++] - '0';
    }
    i++;
    // class
    while (i<line.length()) {
        cls *= 10;
        cls += line[i++] - '0';
    }
    this->reservations.push_back(new MyReservation(id, customerID, flightID, Classes(cls), maxBaggage, this));
    cout << "id: "<< id <<" cusId: "<<  customerID<<" fliID: "<<   flightID<< " cls: "<< cls << " max: "<<maxBaggage<< endl;

}

void Collection::load(){
    string line;
    // Object to write in file
    ifstream file_obj;
    // Opening file in append mode
    file_obj.open("data.txt", ios::in);
    if(file_obj.is_open()) {
        while (line != "EOF" && getline(file_obj, line)) {
            switch (line[0]) {
                case 'c':
                    loadCustomer(line);
                    break;
                case 'e':
                    loadEmployee(line);
                    break;
                case 'f':
                    loadFlight(line);
                    break;
                case 'p':
                    loadPlane(line);
                    break;
                case 'r':
                    loadReservation(line);
                    break;
                default:
                    break;
            }
        }
        cout <<"finish load"<<endl;
        file_obj.close();
    }
}

bool Collection::isBusy(Employee* e, Date date) {
    for (auto &f : getFlights()){
        for (auto &busy : f->getAssignedCrew()){
            if (busy->getID() == e->getID() && f->getDate() == date){
                return true;
            }
        }
    }
    return false;
}

bool Collection::isBusy(Plane* plane, Date date) {
    for (auto &f : getFlights()) {
        if (f->getModelNumber() == plane->getModelNumber() && f->getDate() == date){
            return true;
        }
    }
    return false;
}

Plane *Collection::getPlane(int modelNumber) {
    for (auto &plane: this->planes) {
        if(plane->getModelNumber() == modelNumber)
            return plane;
    }
    return nullptr;
}


bool Collection::isBusy(Flight* flight){
    Plane* p = getPlane(flight->getModelNumber());
    int economy = p->getMaxEconomyClass();
    int first = p->getMaxFirstClass();
    for (auto &r : getReservations()){
        if (r->getFlight()->getID() == flight->getID()){
            if (r->getClass() == FIRST_CLASS) {first--;}
            if (r->getClass() == SECOND_CLASS) {economy--;}
            if (economy < 0 || first < 0) { return true;}
        }
    }

    return false;
}

Collection::~Collection() {
    for (auto &reservation : this->reservations) { delete reservation; }
    for (auto &flight : this->flights) { delete flight; }
    for (auto &plane : this->planes) { delete plane; }
    for (auto &employee : this->employees) { delete employee; }
    for (auto &customer : this->customers) { delete customer; }
}