#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "defs.h"

/*
  Class:    Animal
  Purpose:  Represents an animal client of the veterinary clinic.
*/

class Animal
{
  friend ostream& operator<<(ostream&, Animal&);

  public:
    Animal(SpeciesType s, string n, string g, int yrs, int mths, string prnt);
    int& getId();
    int& getAge();
    string& getName();
    string& getParentName();

  private:
    static int nextId;
    int id;
    SpeciesType species;
    string name;
    string gender;
    int age;
    string parent;
};

#endif