//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_FLIGHT_H
#define AP2_FLIGHT_H

#include "interface.h"
#include "Collection.h"

class MyFlight : public Flight {
private:
    int modelNumber;
    list<Reservation*> reservations;
    list<Employee*> assignedCrew;
    Date date;
    string source;
    string destination;
    string ID;

    void createCrew(Collection* collection);



public:
    int getModelNumber();
    list<Reservation*> getReservations();
    list<Employee*> getAssignedCrew();
    Date getDate();
    string getSource();
    string getDestination();
    string getID();

    MyFlight(int model_number, Date date, string &source, string &destination, Collection* collection);
    MyFlight(string &id, int model_number, Date date, string &source, string &destination, Collection* collection);
};

#endif //AP2_FLIGHT_H