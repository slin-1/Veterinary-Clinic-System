#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

/*
  Author:   Steven Lin
  Purpose:  The user is able to interact with a veterinary clinic schedule of appointments.
  Usage:    The user can do the following in the terminal:
              (1) Print schedule
              (2) Create appointment
              (3) Print animals
              (0) Exit
*/

int main() {
  Control controlLaunch;
  controlLaunch.launch();
  return 0;
}

Control::Control() : schedule(new Schedule){
  animals.setBehaviour(new CompareAge<Animal>(false));
}

Control::~Control() {
  delete schedule;
  animals.cleanupData();
}

void Control::launch() {
  int choice = -1;

  string welcomeMsg = "Hello! Welcome to Steven Lin's Veterinary Clinic";
  cout << "======================================" << endl;
  cout << welcomeMsg << endl;
  cout << "======================================" << endl;

  initAnimals();
  initSchedule();
  
  view->showMenu(choice);

  while (choice != 0) {
    if (choice == 1) {
      cout << (*schedule) << endl;
    }
    else if (choice == 2) {
      int animalId, year, month, day, hours, minutes;

      cout << "Enter animal id: ";
      view->readInt(animalId);
      cout << "Enter appointment year: ";
      view->readInt(year);
      cout << "Enter appointment month: ";
      view->readInt(month);
      cout << "Enter appointment day: ";
      view->readInt(day);
      cout << "Enter appointment hour: ";
      view->readInt(hours);
      cout << "Enter appointment minute: ";
      view->readInt(minutes);

      addAppt(animalId, year, month, day, hours, minutes);
    }
    else if (choice == 3) {
      cout << animals << endl;
    }
      
    view->showMenu(choice);
  }
}

bool Control::addAppt(int animalId, int year, int month, int day, int hours, int mins) {
  Animal* foundAnimal;
  if (animals.find(animalId, &foundAnimal)) {
    schedule->addAppt(foundAnimal, year, month, day, hours, mins);
    return true;
  }
  else {
    cout << "ERROR:  ANIMAL ID " << animalId << " was not found" << endl;
    return false;
  }
}

void Control::initAnimals()
{
  animals.add(new Animal(C_DOG, "Josie", "F", 1, 6, "Stacey"));
  animals.add(new Animal(C_DOG, "Nala", "F", 5, 0, "NONE"));
  animals.add(new Animal(C_DOG, "Miley", "F", 3, 5, "Tim"));
  animals.add(new Animal(C_DOG, "Matcha", "M", 2, 7, "NONE"));
  animals.add(new Animal(C_CAT, "Maya", "F", 11, 0, "Layla"));
  animals.add(new Animal(C_SPEC_OTHER, "Jojo", "M", 0, 3, "Mai"));
  animals.add(new Animal(C_DOG, "Levi", "M", 4, 0, "Stacey"));
  animals.add(new Animal(C_SPEC_OTHER, "Tank", "M", 1, 4, "Sharon"));
  animals.add(new Animal(C_CAT, "Zane", "M", 5, 2, "Frank"));
  animals.add(new Animal(C_CAT, "Prince", "M", 7, 0, "Frank"));
  animals.add(new Animal(C_SPEC_OTHER, "Vader", "M", 0, 3, "Mai"));
  animals.add(new Animal(C_SPEC_OTHER, "Aries", "M", 0, 3, "Mai"));
  animals.add(new Animal(C_CAT, "Maggie", "F", 8, 0, "NONE"));
  animals.add(new Animal(C_CAT, "Ruby", "F", 5, 0, "NONE"));
  animals.add(new Animal(C_SPEC_OTHER, "Biscuit", "F", 3, 8, "Layla"));
  animals.add(new Animal(C_SPEC_OTHER, "Nero", "M", 9, 0, "Sharon"));
}

void Control::initSchedule()
{
  addAppt(1002, 2023, 5, 10, 11, 15);
  addAppt(1005, 2023, 5, 10, 11, 30);	// conflict
  addAppt(1005, 2023, 5, 10, 11, 45);
  addAppt(1012, 2023, 5, 10, 11, 45);	// conflict
  addAppt(1012, 2023, 5, 10, 12, 0);	// conflict
  addAppt(1015, 2023, 5, 10, 11, 0);	// conflict
  addAppt(1015, 2023, 5, 10, 11, 0);	// conflict
  addAppt(1013, 2023, 6, 8, 10, 0);
  addAppt(1007, 2023, 6, 8, 9, 45);	// conflict
  addAppt(1007, 2023, 6, 8, 9, 30);
  addAppt(1010, 2023, 5, 9, 11, 15);

  addAppt(1035, 2023, 6, 8, 11, 15);	// error
  addAppt(1006, 2018, 5, 8, 11, 45);	// error
  addAppt(1006, 2023, 14, 1, 11, 45);	// error
  addAppt(1006, 2023, 5, 41, 11, 45);	// error
  addAppt(1006, 2023, 5, 8, 1, 45);	// error
  addAppt(1006, 2023, 5, 8, 11, 25);	// error
}