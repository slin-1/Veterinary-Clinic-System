#include "Appt.h"

int Appt::nextId = APPT_IDS;

Appt::Appt(Animal* a, Date* d) : id(nextId), animal(a), date(d) {
  nextId++;
}

Appt::~Appt() {
  delete date;
}

bool Appt::sameDay(Appt* other) const {
  return (date->sameDay(*other->date));
}

int Appt::getId() const {
  return id;
}

Date& Appt::getDate() const {
  return *date;
}

ostream& operator<<(ostream& output, Appt& appt) {
  output << appt.id << "   " << *(appt.date) << " @ " << appt.date->getTime()
         << " -- " << left << setw(10) << setfill(' ') << appt.animal->getName()
         << "with parent " << appt.animal->getParentName();

  return output;
}