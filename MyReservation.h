//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_MYRESERVATION_H
#define AP2_MYRESERVATION_H

#include "interface.h"
#include "Collection.h"

class MyReservation : public Reservation {
private:
    Customer* customer;
    Flight* flight;
    Classes cls;
    int maxBaggage;
    string ID;

public:
    Customer* getCustomer();
    Flight* getFlight();
    Classes getClass();
    int getMaxBaggage();
    string getID();
    MyReservation(string customerId, string flightId, Classes cls, int max_baggage, Collection* collection);
    MyReservation(string id,string customerId, string flightId, Classes cls, int max_baggage, Collection* collection);
    void createReservation(Collection* collection);
};


#endif //AP2_MYRESERVATION_H