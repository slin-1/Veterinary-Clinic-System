#ifndef APPT_H
#define APPT_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "defs.h"
#include "Animal.h"
#include "Date.h"

/*
  Class:    Appt
  Purpose:  Manages appointments at a veterinary clinic.
*/

class Appt {
  friend ostream& operator<<(ostream& output, Appt& appt);

  public:
    Appt(Animal* a=NULL, Date* d=NULL);
    ~Appt();
    bool sameDay(Appt* other) const;
    int getId() const;
    Date& getDate() const;

  private:
    static int nextId;
    int id;
    Animal* animal;
    Date* date;
};

#endif