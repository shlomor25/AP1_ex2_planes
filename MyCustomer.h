//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_MYCUSTOMER_H
#define AP2_MYCUSTOMER_H

#include "interface.h"
#include "Collection.h"

class MyCustomer : public Customer{
private:
    string fullName;
    int priority;
    list<Reservation*> reservations;
    string ID;

public:
    MyCustomer(string &fullname, int priority, Collection* collection);
    MyCustomer(string &id, string &fullname, int priority, Collection* collection);
    string getFullName();
    int getPriority();
    list<Reservation*> getReservations();
    string getID();
    void searchReservation(Collection* collection);
};


#endif //AP2_MYCUSTOMER_H