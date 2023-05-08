#include "Animal.h"

int Animal::nextId = ANIMAL_IDS;

Animal::Animal(SpeciesType s, string n, string g, int yrs, int mths, string prnt) 
    : id(nextId), species(s), name(n), gender(g), parent(prnt) {
  if (yrs > 0) {
    mths += (12 * yrs);
  }
  age = mths;
  nextId++;
}

int& Animal::getId() {
  return id;
}

int& Animal::getAge() {
  return age;
}

string& Animal::getName() {
  return name;
}

string& Animal::getParentName() {
  return parent;
}

ostream& operator<<(ostream& output, Animal& animal) {
  int ageYears = animal.age / 12;
  int ageMonths = animal.age - (ageYears * 12);
  string strSpecies;
  string verifyParent;

  if (animal.species == 0) {
    strSpecies = "Dog";
  }
  else if (animal.species == 1) {
    strSpecies = "Cat";
  }
  else {
    strSpecies = "Other";
  }

  if (animal.parent.empty()) {
   verifyParent = "NONE";
  }
  else {
    verifyParent = animal.parent;
  }

  output << animal.id << ":  " << left << setw(10) << setfill(' ') << animal.name << ":   " << setw(5) 
         << strSpecies << ";   Age:" << right << setw(4) << ageYears << " yrs, " 
         << left << setw(4) << ageMonths << "mths;  Parent: " << verifyParent;

  return output;
}