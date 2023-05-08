#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
  Class:    Time
  Purpose:  Manages the time for the program. Overloads the == and < operators
            for the time class.
*/

class Time
{
  friend ostream& operator<<(ostream&, Time&);

  public:
    Time(int hours=0, int minutes=0);
    void setTime(int hours, int minutes);
    void add(int hours, int minutes);
    bool operator==(Time& time);
    bool operator<(Time& time);

  private:
    int hours;
    int minutes;
    int convertToMins() const;
};

#endif
