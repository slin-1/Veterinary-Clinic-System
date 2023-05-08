#include "Time.h"

Time::Time(int hours, int minutes) {
  setTime(hours, minutes);
}

void Time::setTime(int hours, int minutes) {
  this->hours   = ( hours >= 0 && hours < 24) ? hours : 0;
  this->minutes = ( minutes >= 0 && minutes < 60) ? minutes : 0;
}

bool Time::operator==(Time& time) {
  return ( this->convertToMins() == time.convertToMins() );
}

bool Time::operator<(Time& time) {
  return ( this->convertToMins() < time.convertToMins() );
}

ostream& operator<<(ostream& output, Time& time) {
  output << setfill('0') << setw(2) << time.hours << ":"
         << setfill('0') << setw(2) << time.minutes;

  return output;
}

int Time::convertToMins() const {
  return (hours*60 + minutes);
}

void Time::add(int hours, int minutes) {
  int totalMinutes = this->convertToMins() + (hours*60 + minutes);
  this->hours = totalMinutes / 60;
  this->minutes = totalMinutes % 60;
}