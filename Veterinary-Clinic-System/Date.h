#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

/*
  Class:    Date
  Purpose:  Manages the dates for the program. Overloads the ==, <, and > operators
            for the Date class (involving the date and time).
*/

class Date
{
  friend ostream& operator<<(ostream&, Date&);

  public:
    Date(int d=0, int m=0, int y=2000, int hrs=0, int mins=0);
    void setDate(int d,int m,int y);
    Time& getTime();
    bool operator==(Date& date);
    bool operator<(Date& date);
    bool operator>(Date& date);
    static bool validate(int day, int month, int year);
    bool sameDay(Date& date);

  private:
    int day;
    int month;
    int year;
    Time time;
    int  lastDayInMonth();
    bool leapYear();
    bool lessThan(Date& date);
};

#endif