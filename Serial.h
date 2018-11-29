//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#ifndef AP2_SERIAL_H
#define AP2_SERIAL_H

#include <string>
using namespace std;

class Serial {
public:
    static string serial();
    void static init();

private:
    Serial();
};

#endif //AP2_SERIAL_H