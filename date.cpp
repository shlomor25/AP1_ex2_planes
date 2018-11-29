//
// Created by shlomo Rabinovich 308432517 on 26/11/18.
//

#include "interface.h"

int getYear(string date){
    int year = 0;
    for (int i = 0; i < 4; i++) {
        year *= 10;
        year += date[i];
    }
    return year;
}

int getMonth(string date){
    int month = 0;
    for (int i = 5; i < 7; i++) {
        month *= 10;
        month += date[i];
    }
    return month;
}

int getDay(string date){
    int day = 0;
    for (int i = 8; i < 10; i++) {
        day *= 10;
        day += date[i];
    }
    return day;
}

Date::Date(string date)
{
    if (date.length() != 10)
        throw "Illegal argument";
    this->date = date;
}

bool Date::operator<(const Date& d) const
{
    int y1 = getYear(this->date);
    int y2 = getYear(d.date);
    int m1 = getMonth(this->date);
    int m2 = getMonth(d.date);
    int d1 = getDay(this->date);
    int d2 = getDay(d.date);

    /* compare year, month and day */
    if (y1 != y2) { return y1 < y2;}
    if (m1 != m2) { return m1 < m2;}
    if (d1 != d2) { return d1 < d2;}
    return true;
}

bool Date::operator>(const Date& d) const
{
    /* int y1 = getYear(this->date);
     int y2 = getYear(d.date);
     int m1 = getMonth(this->date);
     int m2 = getMonth(d.date);
     int d1 = getDay(this->date);
     int d2 = getDay(d.date);*/
    // if not equal or <
    return !(*this == d || *this < d);
}

bool Date::operator==(const Date& d) const
{
    int y1 = getYear(this->date);
    int y2 = getYear(d.date);
    int m1 = getMonth(this->date);
    int m2 = getMonth(d.date);
    int d1 = getDay(this->date);
    int d2 = getDay(d.date);

    return (y1 == y2 && m1 == m2 && d1 == d2);
}

