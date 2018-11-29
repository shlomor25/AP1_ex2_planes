//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_COLLECTION_H
#define AP2_COLLECTION_H


#include "interface.h"

class Collection {
private:
    list<Reservation*> reservations;
    list<Plane*> planes;
    list<Employee*> employees;
    list<Flight*> flights;
    list<Customer*> customers;

public:
    list<Reservation*> getReservations();
    list<Plane*> getPlanes();
    list<Employee*> getEmployees();
    list<Flight*> getFlights();
    list<Customer*> getCustomers();

    Reservation* getReservation(string &reservationID);
    Plane* getPlane(string &planeID);
    Plane* getPlane(int modelNumber, Date date);
    Employee* getEmployee(string &employeeID);
    Flight* getFlight(string &flightID);
    Customer* getCustomer(string &customerID);

    void addReservation(Reservation* reservation);
    void addPlane(Plane* plane);
    void addEmployee(Employee* employee);
    void addFlight(Flight* flight);
    void addCustomer(Customer* customer);
    void load();
    void save();
    void loadEmployee(string &line);
    void loadCustomer(string &line);
    void loadFlight(string &line);
    void loadPlane(string &line);
    void loadReservation(string &line);

    bool isBusy(Employee* e, Date date);
    bool isBusy(Plane* plane, Date date);
    bool isBusy(Flight* flight);

    Plane* getPlane(int modelNumber);

    ~Collection();
};


#endif //AP2_COLLECTION_H