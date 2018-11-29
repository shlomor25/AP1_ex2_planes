//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_MYPLANE_H
#define AP2_MYPLANE_H

#include "interface.h"
#include "Collection.h"

class MyPlane : public Plane {
private:
    int modelNumber;
    map<Jobs, int> crewNeeded;
    int maxFirstClass;
    int maxEconomyClass;
    string ID;

public:
    int getModelNumber();
    map<Jobs, int> getCrewNeeded();
    int getMaxFirstClass();
    int getMaxEconomyClass();
    string getID();
    MyPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers, Collection* collection);
    MyPlane(string &id, int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers, Collection* collection);
};


#endif //AP2_MYPLANE_H