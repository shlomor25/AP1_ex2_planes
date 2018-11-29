//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "MyImplementation.h"

Employee *MyImplementation::addEmployee(int seniority, int birth_year, string employer_id, Jobs title) {
    loadData();
    Employee* employee = new MyEmployee(seniority, birth_year, employer_id, title, &this->collection);
    collection.addEmployee(employee);
    cout << "Employee added successfully" << endl;
    return employee;
}

Employee *MyImplementation::getEmployee(string id) {
    loadData();
    return this->collection.getEmployee(id);
}

Plane *MyImplementation::addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers) {
    loadData();
    Plane *plane = new MyPlane(model_number, crew_needed, max_passangers, &this->collection);
    collection.addPlane(plane);
    cout << "Plane Added successfully" << endl;
    return plane;
}

Plane *MyImplementation::getPlane(string id) {
    loadData();
    return this->collection.getPlane(id);
}

Flight *MyImplementation::addFlight(int model_number, Date date, string source, string destination) {
    loadData();
    try {

        Flight* flight = new MyFlight(model_number, date, source, destination, &this->collection);
        collection.addFlight(flight);
        cout << "Flight added successfully" << endl;
        return flight;
    } catch (const char* s) { cout << s << endl; }
}

Flight *MyImplementation::getFlight(string id) {
    loadData();
    return this->collection.getFlight(id);
}

Customer *MyImplementation::addCustomer(string full_name, int priority) {
    loadData();
    Customer* customer = new MyCustomer(full_name, priority, &this->collection);
    collection.addCustomer(customer);
    cout << "Customer added successfully" << endl;
    return customer;
}

Customer *MyImplementation::getCustomer(string id) {
    loadData();
    return this->collection.getCustomer(id);
}

Reservation *MyImplementation::addResevation(string customerId, string flightId, Classes cls, int max_baggage) {
    loadData();
    try {
        Reservation *reservation = new MyReservation(customerId, flightId, cls, max_baggage, &this->collection);
        collection.addReservation(reservation);
        cout << "Reservation added successfully" << endl;
        return reservation;
    } catch (const char* s) { cout << s << endl; }
}

Reservation *MyImplementation::getReservation(string id) {
    loadData();
    return this->collection.getReservation(id);
}

void MyImplementation::exit() {
    collection.save();
}

MyImplementation::MyImplementation(){
    this->dataFlag = false;
    Serial::init();
}

void MyImplementation::loadData(){
    if (!dataFlag) {
        cout <<"loading..." << endl;
        collection.load();
        dataFlag = true;
    }
}