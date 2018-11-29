//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_MYEMPLOYEE_H
#define AP2_MYEMPLOYEE_H

#include "interface.h"
#include "Collection.h"

class MyEmployee : public Employee
{
private:
    int seniority;
    int birthYear;
    Jobs title;
    string ID;
    Employee* employer;

public:
    MyEmployee(int seniority, int birthYear, string employerID, Jobs title, Collection* collection);
 //   MyEmployee(string id, Collection* collection);
    MyEmployee(int seniority, int birthYear, string employerID, Jobs title, string id, Collection* collection);
    int getSeniority();
    int getBirthYear();
    Employee* getEmployer();
    Jobs getTitle();
    string getID();
};

#endif //AP2_MYEMPLOYEE_H