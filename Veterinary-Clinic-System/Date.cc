#include "Date.h"

Date::Date(int d, int m, int y, int hrs, int mins) {
  setDate(d, m, y);
  time.setTime(hrs, mins);
}

void Date::setDate(int d,int m,int y) {
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

Time& Date::getTime() {
  return time;
}

bool Date::operator==(Date& date) {
  return (sameDay(date) && (this->time == date.time));
}

bool Date::operator<(Date& date) {
  if (sameDay(date) && (this->time < date.time)) {
    return true;
  }

  return (this->lessThan(date));
}

bool Date::operator>(Date& date) {
  return (!(*this < date || *this == date));
}

ostream& operator<<(ostream& output, Date& date) {
  output << right << setfill('0') << setw(4) << date.year << "-"
         << right << setfill('0') << setw(2) << date.month << "-"
         << right << setfill('0') << setw(2) << date.day;

  return output;
}

bool Date::validate(int day, int month, int year) {
  if (month < 1 || month > 12) {
    return false;
  }
  if (day < 1 || day > 31) {
    return false;
  }

  Date tempDate(day, month, year);
  int lastDay = tempDate.lastDayInMonth();

  if (lastDay == 28) {
    return (day <= 28);
  }
  else if (lastDay == 29) {
    return (day <= 29);
  }
  else if (lastDay == 30) {
    return (day <= 30);
  }
  else {
    return (day <= 31);
  }

  return false;
}

bool Date::sameDay(Date& date) {
  if (year == date.year && month == date.month && day == date.day) {
    return true;
  }
  else {
    return false;
  }
}

int Date::lastDayInMonth() {
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear() {
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

bool Date::lessThan(Date& date)
{
  if (year < date.year) {
    return true;
  }
  else if (year == date.year && month < date.month) {
    return true;
  }
  else if (year == date.year && month == date.month && day < date.day) {
    return true;
  }
  else {
    return false;
  }
}