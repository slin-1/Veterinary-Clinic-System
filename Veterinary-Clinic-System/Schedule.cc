#include "Schedule.h"

Schedule::Schedule() {
  appointments.setBehaviour(new CompareDate<Appt>(true));
}

Schedule::~Schedule() {
  appointments.cleanupData();
}

bool Schedule::addAppt(Animal* animal, int year, int month, int day, int hours, int mins) {
  if (verifyDateTimeAppt(year, month, day, hours, mins)) {
    Date* newDate = new Date(day, month, year, hours, mins);
    Appt* newAppt = new Appt(animal, newDate);

    if (!(verifyOverlapAppt(newAppt))) {
      appointments.add(newAppt);
      return true;
    }
    else {
      delete newAppt;
    }
  }

  return false;
}

bool Schedule::verifyDateTimeAppt(int& year, int& month, int& day, int& hours, int& mins) {
  if (year != CURR_YEAR) {
    cout << "ERROR:  Year " << year << " is invalid" << endl;
    return false;
  }

  if (!(Date::validate(day, month, year))) {
    Date tempDate(day, month, year);
    cout << "ERROR:  Date " << tempDate << " is invalid" << endl;
    return false;
  }

  Time tempTime(hours, mins);
  Time lowerBound(OPEN_HRS, 0);
  Time upperBound(CLOSE_HRS, 45);

  if ( !(((lowerBound < tempTime) || (lowerBound == tempTime)) && 
         ((tempTime < upperBound) || (tempTime == upperBound))) ) {
    cout << "ERROR:  Appointment " << tempTime << " is invalid. Must be from 09:00 to 16:45 inclusively." << endl;
    return false;
  }
  else if (mins < 0 || mins > 59 || mins % 15 != 0) {
    cout << "ERROR:  Minutes " << mins << " are invalid" << endl;
    return false;
  }

  return true;
}

bool Schedule::verifyOverlapAppt(Appt* appt) {
  Appt* tempArr[MAX_ARR];
  int size = 0;
  appointments.convertToArray(tempArr, size);

  if (size == 0) {
    return false; 
  }
  
  Time newApptStartTime = appt->getDate().getTime();
  Time newApptEndTime = appt->getDate().getTime();
  newApptEndTime.add(0, APPT_DURATION);

  for (int i=0; i<size; i++) {
    if (!(tempArr[i]->sameDay(appt))) {
      continue;
    }

    Time currStartTime = tempArr[i]->getDate().getTime();
    Time currEndTime = tempArr[i]->getDate().getTime();
    currEndTime.add(0, APPT_DURATION);

    if ((newApptStartTime < currEndTime && currStartTime < newApptEndTime)) {
      cout << "ERROR: Appointment " << appt->getId() << " on " << appt->getDate()
         << " @ " << newApptStartTime << " conflicts with " << tempArr[i]->getId()
         << " on " << tempArr[i]->getDate() << " @ " << currStartTime
         << endl;
      return true;
    }
  }

  return false;
}

ostream& operator<<(ostream& output, Schedule& schedule) {
  output << schedule.appointments;

  return output;
}