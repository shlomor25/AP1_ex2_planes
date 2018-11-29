//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "Serial.h"
#include <string>
#include <ctime>

string Serial::serial() {
    string s;
    static const char letter[]
            = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
              "abcdefghijklmnopqrstuvwxyz"
              "0123456789";

    for (int i = 0; i < 10; i++) {
        s += letter[rand() % (sizeof(letter) - 1)];
    }
    return s;
}

void Serial::init() {
    srand (time(0));
}