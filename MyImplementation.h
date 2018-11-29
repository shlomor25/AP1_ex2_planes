#include "interface.h"
#include "MyCustomer.h"
#include "MyFlight.h"
#include "MyPlane.h"
#include "MyReservation.h"
#include "MyEmployee.h"
#include "Collection.h"
#include "Serial.h"
#include <iostream>

class MyImplementation : public Ex2
{
private:
    Collection collection;
    bool dataFlag;

public:
    Employee *addEmployee(int seniority, int birth_year, string employer_id, Jobs title);
    Employee *getEmployee(string id);
    Plane *addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers);
    Plane *getPlane(string id);
    Flight *addFlight(int model_number, Date date, string source, string destination);
    Flight *getFlight(string id);
    Customer *addCustomer(string full_name, int priority);
    Customer *getCustomer(string id);
    Reservation *addResevation(string customerId, string flightId, Classes cls, int max_baggage);
    Reservation *getReservation(string id);
    void exit();
    MyImplementation();
    void loadData();
};