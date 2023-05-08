#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "defs.h"
#include "List.h"
#include "Appt.h"
#include "Animal.h"

/*
  Class:    Schedule
  Purpose:  Represents the appointement schedule for a veterinary clinic.
*/

class Schedule {
  friend ostream& operator<<(ostream& output, Schedule& schedule);

  public:
    Schedule();
    ~Schedule();
    bool addAppt(Animal* animal, int year, int month, int day, int hours, int mins);

  private:
    //int numAppts;  //not used
    List<Appt> appointments;
    bool verifyDateTimeAppt(int& year, int& month, int& day, int& hours, int& mins);
    bool verifyOverlapAppt(Appt* appt);
    
};

#endif